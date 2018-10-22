#include <QTextCodec>
#include "loadcsv.h"
#include <qdebug.h>
#include "oss/utils/dsm/dsmpub.h"
#include "global.h"
extern char m_appdir[512];
extern int sysid;  //系统id

const char* utf8togbk(char* str)
{
    if(str == NULL)
        return NULL;
    QString string = str;
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QByteArray encodedString = codec->fromUnicode(string);
    str = encodedString.data();
    return str;
}

QString gbktoutf8(char* str)
{
    if(str == NULL)
        return NULL;
    QByteArray encodedString = str;
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QString des = codec->toUnicode(encodedString);
    return des;

}
int i_loadfactormap(factor_map* fidmaps,int sysid)
{
    factor_map fidnode;
    int fidcount = 0;
    char filename[DM_FILEPATH_SIZE];
    char appdir[DM_FILEPATH_SIZE];
    char numfmt[MAX_NUMFMT_SIZE];
    int mysysid = 0;
    char* p = NULL;
    ufilecsv csvfile;

    strcpy(filename, "factor.csv");
    strcpy(appdir, m_appdir);
    strcat(appdir, "const/uid/");
//    qDebug()<<appdir;
    if (csvfile.open(true, appdir, filename))
    {
        while(csvfile.setio())
        {
            memset(&fidnode, 0, sizeof(fidnode));
            numfmt[0] = 0;
            mysysid = 0;
            csvfile.read(utf8togbk("系统ID"),mysysid);
            if (mysysid != sysid)
            {
                continue;
            }
            csvfile.read(utf8togbk("因子分组ID"),fidnode.g_fac);
            csvfile.read(utf8togbk("因子通道ID"),fidnode.fid);
            csvfile.read(utf8togbk("因子名称"),fidnode.fac_name);
            csvfile.read(utf8togbk("单位"),fidnode.unit);
            csvfile.read(utf8togbk("数值格式"),numfmt);
            csvfile.read(utf8togbk("系统ID"),fidnode.sysid);

            p = strstr(numfmt, ".");
            if (p != NULL)
            {
                fidnode.decimalbits = atoi(p+1);
            }

            fidmaps[fidcount] = fidnode;
            fidcount++;
        }
        csvfile.close();
    }

    return fidcount-1;
}


int i_loadcfglistmap(cfglist_map* fidmaps)
{
    cfglist_map fidnode;
    int fidcount = 0;
    char filename[DM_FILEPATH_SIZE];
    char appdir[DM_FILEPATH_SIZE];
    ufilecsv csvfile;

    strcpy(filename, "cfglist.csv");
    strcpy(appdir, m_appdir);
    strcat(appdir, "const/list/");
    if (csvfile.open(true, appdir, filename))
    {
        while(csvfile.setio())
        {
            memset(&fidnode, 0, sizeof(fidnode));
            csvfile.read(utf8togbk("系统ID"),fidnode.sysid);
            csvfile.read(utf8togbk("模板名称"),fidnode.mode_name);
            csvfile.read(utf8togbk("模板ID"),fidnode.mode_id);

            fidmaps[fidcount] = fidnode;
            ++fidcount;
        }
        csvfile.close();
    }

    return fidcount-1;
}

int i_loadsystypemap(systype_map* fidmaps)
{
    systype_map fidnode;
    int fidcount = 0;
    char filename[DM_FILEPATH_SIZE];
    char appdir[DM_FILEPATH_SIZE];
    ufilecsv csvfile;

    strcpy(filename, "systype.csv");
    strcpy(appdir, m_appdir);
    strcat(appdir, "const/uid/");
    if (csvfile.open(true, appdir, filename))
    {
        while(csvfile.setio())
        {
            memset(&fidnode, 0, sizeof(fidnode));
            csvfile.read(utf8togbk("系统ID"),fidnode.sysid);
            csvfile.read(utf8togbk("系统名称"),fidnode.sys_name);

            fidmaps[fidcount] = fidnode;
            ++fidcount;
        }
        csvfile.close();
    }

    return fidcount-1;
}

int i_loaddevlistmap(devlist_map* fidmaps)
{
    devlist_map fidnode;
    int fidcount = 0;
    char filename[DM_FILEPATH_SIZE];
    char appdir[DM_FILEPATH_SIZE];
    ufilecsv csvfile;

    strcpy(filename, "devlist.csv");
    strcpy(appdir, m_appdir);
    strcat(appdir, "const/list/");
    if (csvfile.open(true, appdir, filename))
    {
        while(csvfile.setio())
        {
            memset(&fidnode, 0, sizeof(fidnode));
            csvfile.read(utf8togbk("制造商ID"),fidnode.companyid);
            csvfile.read(utf8togbk("设备型号"),fidnode.devmodel);
            csvfile.read(utf8togbk("系统ID"),fidnode.sysid);
            csvfile.read(utf8togbk("设备类型"),fidnode.devtype);
            csvfile.read(utf8togbk("协议ID"),fidnode.protocol);
            csvfile.read(utf8togbk("设备能力"),fidnode.devcapacity);

            fidmaps[fidcount] = fidnode;
            ++fidcount;
        }
        csvfile.close();
    }

    return fidcount-1;
}
int i_loaddevmap(dev_map* fidmaps,char* curfilename)
{
    dev_map fidnode;
    int fidcount = 0;
    char filename[DM_FILEPATH_SIZE];
    char appdir[DM_FILEPATH_SIZE];
    ufilecsv csvfile;

    strcpy(filename, curfilename);
    strcpy(appdir, m_appdir);
    strcat(appdir, "const/dev/");
    if (csvfile.open(true, appdir, filename))
    {
        while(csvfile.setio())
        {
            memset(&fidnode, 0, sizeof(fidnode));
            csvfile.read(utf8togbk("设备型号"),fidnode.devmodel);
            csvfile.read(utf8togbk("通道类型"),fidnode.porttype);
            csvfile.read(utf8togbk("通道编号"),fidnode.portnum);
            csvfile.read(utf8togbk("通道名称"),fidnode.portname);
            csvfile.read(utf8togbk("通道标识"),fidnode.portsign);


            fidmaps[fidcount] = fidnode;
            ++fidcount;
        }
        csvfile.close();
    }

    return fidcount-1;
}
int i_loaddtplistmap(dtplist_map* fidmaps)
{
    dtplist_map fidnode;
    int fidcount = 0;
    char filename[DM_FILEPATH_SIZE];
    char appdir[DM_FILEPATH_SIZE];
    ufilecsv csvfile;

    strcpy(filename, "dtplist.csv");
    strcpy(appdir, m_appdir);
    strcat(appdir, "const/list/");
    if (csvfile.open(true, appdir, filename))
    {
        while(csvfile.setio())
        {
            memset(&fidnode, 0, sizeof(fidnode));
            csvfile.read(utf8togbk("协议名称"),fidnode.protocolname);
            csvfile.read(utf8togbk("协议ID"),fidnode.protocolid);
            csvfile.read(utf8togbk("通信模式"),fidnode.model);
            fidmaps[fidcount] = fidnode;
            ++fidcount;
        }
        csvfile.close();
    }

    return fidcount-1;
}

int getappdirex(char* appdir, int size, int layer)
{
    char szBuffer[512];
    char* p = NULL;
    int count = layer;

    if (count < 0)
    {
        count = 0;
    }

    memset(szBuffer, 0, sizeof(szBuffer) );
    QString dir = QDir::currentPath();
    dir.replace("/","\\");
    dir.append("\\");
    QByteArray ba = dir.toLatin1();
    strcpy(szBuffer,ba.data());

    while(count > 0)
    {
        p = strrchr(szBuffer,'\\');

        if (p == NULL)
        {
            break;
        }

        count--;

        if (count > 0)
        {
            p[0] = 0;
        }
    }

    if (count > 0)
    {
        appdir[0] = 0;
        return -1;
    }

    p[1] = 0;

    if (strlen(szBuffer) >= size)
    {
        return -2;
    }

    strcpy(appdir, szBuffer);
    return 0;
}
