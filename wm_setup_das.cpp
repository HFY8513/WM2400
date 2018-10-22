#include "wm_setup_das.h"
#include "ui_wm_setup_das.h"
#include <qDebug>
#include <QStandardItemModel>

extern utrace g_qttrace;
extern char m_appdir[512];
//extern factor_map g_fidmaps[MAX_DAQ_ITEM];
WM_SETUP_DAS::WM_SETUP_DAS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WM_SETUP_DAS)
{
    ui->setupUi(this);
    initPage();
    initFrom();
}

WM_SETUP_DAS::~WM_SETUP_DAS()
{
    delete ui;
}

void WM_SETUP_DAS::initPage()
{
    uci myuci;
    char appdir[DM_FILEPATH_SIZE];
    strcpy(appdir,m_appdir);

    if (myuci.init(&g_qttrace, appdir) != 0)
    {
        qDebug()<<-2;
    }

    memset(&m_mainparam, 0, sizeof(m_mainparam));
    memset(&m_dasparam, 0, sizeof(m_dasparam));

    if (myuci.readmain(&m_mainparam) != 0)
    {
        //return -3;
    }
    if (myuci.readdas(&m_dasparam) != 0)
    {
        //return -7;
    }
//    memcpy(&g_dasparam,&m_dasparam,sizeof(appdas_param));
    initComTable();
    initTcpTable();
    initDevTable();
    initFidTable();
}

void WM_SETUP_DAS::initFrom()
{
    QTreeWidget* treeWidget = ui->treeWidget;//我已经在ui设计师中拖了一个QTreeWidget

    treeWidget->expandAll();

    QString headers;
    headers  = "采集设置" ;
    treeWidget->setHeaderLabel(headers);

    QStringList rootText;
    rootText  << "wells";

    connect(treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(checkself(QTreeWidgetItem* ,int)));//检测点击事件，信号槽机制
}

void WM_SETUP_DAS::initComTable()
{
    QList<QString> columnNames; //字段名集合
    columnNames<<tr("串口名称")<<tr("串口号")<<tr("波特率")<<tr("数据位")<<tr("校验位")<<tr("停止位");


    QStandardItemModel  *item_model = new QStandardItemModel(m_dasparam.uiocomcount,6);
    for (int i = 0; i < 6; i++) {
        item_model->setHeaderData(i, Qt::Horizontal, columnNames.at(i));
        //tableView->setColumnWidth(i, columnWidths.at(i));
    }
     QStringList comList  ;

     comList<<tr("None")<<tr("Odd")<<tr("Even")<<tr("Mark")<<tr("Space");
    for(int i = 0;i<m_dasparam.uiocomcount;i++)
    {
        item_model->setItem(i,0,new QStandardItem(m_dasparam.uiocomparams[i].logicname));
        item_model->setItem(i,1,new QStandardItem(m_dasparam.uiocomparams[i].phyname));
        item_model->setItem(i,2,new QStandardItem(QString::number(m_dasparam.uiocomparams[i].param.baud_rate)));
        item_model->setItem(i,3,new QStandardItem(QString::number(m_dasparam.uiocomparams[i].param.byte_size)));
        item_model->setItem(i,4,new QStandardItem(comList.at(m_dasparam.uiocomparams[i].param.parity)));
        item_model->setItem(i,5,new QStandardItem(QString::number(m_dasparam.uiocomparams[i].param.stop_bits)));
    }

    ui->tabv_com->setModel(item_model);          // 关联view与model
    ui->tabv_com->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
    //ui->tabv_comhorizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );//根据列内容来定列宽
    //ui->tabv_com->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//对第0列单独设置固定宽度
    ui->tabv_com-> setColumnWidth(0, 45);//设置固定宽度


    ItemDelegate *item2 = new ItemDelegate();
    item2->setComType(COMB_COM);
    ui->tabv_com->setItemDelegateForColumn(1, item2);

    ItemDelegate *item3 = new ItemDelegate();
    item3->setComType(COMB_BRATE);
    ui->tabv_com->setItemDelegateForColumn(2, item3);

    ItemDelegate *item4 = new ItemDelegate();
    item4->setComType(COMB_DATABIT);
    ui->tabv_com->setItemDelegateForColumn(3, item4);

    ItemDelegate *item5 = new ItemDelegate();
    item5->setComType(COMB_CHECKBIT);
    ui->tabv_com->setItemDelegateForColumn(4, item5);

    ItemDelegate *item6 = new ItemDelegate();
    item6->setComType(COMB_STOPBIT);
    ui->tabv_com->setItemDelegateForColumn(5, item6);

}

void WM_SETUP_DAS::initTcpTable()
{
    QList<QString> columnNames; //字段名集合
    columnNames<<tr("网口名称")<<tr("IP")<<tr("PORT");


    QStandardItemModel  *item_model = new QStandardItemModel(m_dasparam.uiotcpcount,3);
    for (int i = 0; i < 3; i++) {
        item_model->setHeaderData(i, Qt::Horizontal, columnNames.at(i));
    }

    for(int i = 0;i<m_dasparam.uiotcpcount;i++)
    {
        item_model->setItem(i,0,new QStandardItem(m_dasparam.uiotcpparams[i].logicname));
        item_model->setItem(i,1,new QStandardItem(m_dasparam.uiotcpparams[i].param.host));
        item_model->setItem(i,2,new QStandardItem(QString::number(m_dasparam.uiotcpparams[i].param.port)));
    }

    ui->tabv_tcp->setModel(item_model);          // 关联view与model
    ui->tabv_tcp->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
}

void WM_SETUP_DAS::initDevTable()
{
    QList<QString> columnNames; //字段名集合
    columnNames<<tr("设备名称")<<tr("设备型号")<<tr("接口类型")<<tr("接口名称")<<tr("设备地址")<<tr("设备周期(秒)");

    QStandardItemModel  *item_model = new QStandardItemModel(m_dasparam.devcount,6);
    for (int i = 0; i < 6; i++) {
        item_model->setHeaderData(i, Qt::Horizontal, columnNames.at(i));
    }
    for(int i = 0;i<m_dasparam.devcount;i++)
    {
        item_model->setItem(i,0,new QStandardItem(m_dasparam.devparams[i].name));
        item_model->setItem(i,1,new QStandardItem(QString::number(m_dasparam.devparams[i].devtype)));
        item_model->setItem(i,2,new QStandardItem(QString::number(m_dasparam.devparams[i].inftype)));
        item_model->setItem(i,3,new QStandardItem(m_dasparam.devparams[i].logicname));
        item_model->setItem(i,4,new QStandardItem(QString::number(m_dasparam.devparams[i].addr)));
        item_model->setItem(i,5,new QStandardItem(QString::number(m_dasparam.devparams[i].devperiod)));
    }

    ui->tabv_dev->setModel(item_model);          // 关联view与model
    ui->tabv_dev->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
}

void WM_SETUP_DAS::initFidTable()
{
    QList<QString> columnNames; //字段名集合
    columnNames<<tr("因子名称")<<tr("设备名称")<<tr("设备通道")<<tr("设备单位")<<tr("采集最小值")<<tr("采集最大值")<<tr("转换最小值")<<tr("转换最大值")<<tr("斜率")<<tr("截距");

    QStandardItemModel  *item_model = new QStandardItemModel(m_dasparam.fchcount,10);
    for (int i = 0; i < 10; i++) {
        item_model->setHeaderData(i, Qt::Horizontal, columnNames.at(i));
    }

    for(int i = 0;i<m_dasparam.fchcount;i++)
    {
        factor_map fidmaps[MAX_DAQ_ITEM];
        int cursysid = 0;
        for(int i = 0;i<m_mainparam.mnodecount;i++)
        {
            if(m_dasparam.fchparams[i].stationid == m_mainparam.mnodeparams[i].stationid)
            {
                cursysid = m_mainparam.mnodeparams[i].sysid;
//                //mytableWidget->setItem(loop,0,new QTableWidgetItem(m_mainparam.mnodeparams[i].name));
                break;
            }
        }
        int fcount = i_loadfactormap(fidmaps,cursysid);

        for(int j = 0;j < fcount;j++)
        {
            if(convertfidrule(m_dasparam.fchparams[i].fid)==fidmaps[j].fid)
            {
                item_model->setItem(i,0,new QStandardItem(gbktoutf8(fidmaps[j].fac_name)));
                //mytableWidget->setItem(loop,1,new QTableWidgetItem(gbktoutf8(fidmaps[i].fac_name)));
                break;
            }
        }

        //item_model->setItem(i,0,new QStandardItem(m_dasparam.fchparams[i].name));
        item_model->setItem(i,1,new QStandardItem(m_dasparam.fchparams[i].devname));
        item_model->setItem(i,2,new QStandardItem(QString::number(m_dasparam.fchparams[i].channel)));
        item_model->setItem(i,3,new QStandardItem(m_dasparam.fchparams[i].unit));
        item_model->setItem(i,4,new QStandardItem(QString::number(m_dasparam.fchparams[i].devmax)));
        item_model->setItem(i,5,new QStandardItem(QString::number(m_dasparam.fchparams[i].devmin)));
        item_model->setItem(i,6,new QStandardItem(QString::number(m_dasparam.fchparams[i].rangemax)));
        item_model->setItem(i,7,new QStandardItem(QString::number(m_dasparam.fchparams[i].rangemin)));
        item_model->setItem(i,8,new QStandardItem(QString::number(m_dasparam.fchparams[i].slope)));
        item_model->setItem(i,9,new QStandardItem(QString::number(m_dasparam.fchparams[i].intercept)));
    }

    ui->tabv_fid->setModel(item_model);          // 关联view与model
    ui->tabv_fid->setColumnWidth(1, 150);//设置固定宽度
    ui->tabv_fid->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
    ui->tabv_fid->setColumnWidth(0, 100);//设置固定宽度

}


void WM_SETUP_DAS::checkself(QTreeWidgetItem *item, int column)
{
    QTreeWidgetItem *parent= item->parent();;
    //int col = parent->indexOfChild(item); //item在父项中的节点行号(从0开始)

    int level = 0;

    while(NULL!=parent)
    {
        level++;
        parent  = parent->parent();

    }
    ui->stackedDas->setCurrentIndex(level);

}

QWidget * ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    switch (m_type) {
    case COMB_COM:
        for (int i = 0; i < sizeof(comnum)/sizeof(comnum[0]); i++)
            editor->addItem(QWidget::tr(comnum[i]));
        break;
    case COMB_BRATE:
        for (int i = 0; i < sizeof(baudrate)/sizeof(baudrate[0]); i++)
            editor->addItem(QWidget::tr(baudrate[i]));
        break;
    case COMB_DATABIT:
        for (int i = 0; i < sizeof(databit)/sizeof(databit[0]); i++)
            editor->addItem(QWidget::tr(databit[i]));
        break;
    case COMB_CHECKBIT:
        for (int i = 0; i < sizeof(checkbit)/sizeof(checkbit[0]); i++)
            editor->addItem(QWidget::tr(checkbit[i]));
        break;
    case COMB_STOPBIT:
        for (int i = 0; i < sizeof(stopbit)/sizeof(stopbit[0]); i++)
            editor->addItem(QWidget::tr(stopbit[i]));
        break;
    default:
        break;
    }
    return editor;
}



void ItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    int tindex = comboBox->findText(text);
    comboBox->setCurrentIndex(tindex);
}
void ItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString text = comboBox->currentText();
    if(text!="")
        model->setData(index, text, Qt::EditRole);
}

void ItemDelegate::setComType(COMBType _type)
{
    m_type=_type;
}
