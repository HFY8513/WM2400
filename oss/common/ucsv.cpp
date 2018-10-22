#include "ucsv.h"

int replace(string& src_str, const string& old_str, const string& new_str)  
{  
    int count   = 0;  
    int old_str_len = int(old_str.length());  
    int new_str_len = int(new_str.length());  
    int pos = 0;  
    while((pos=int(src_str.find(old_str,pos)))!=string::npos)  
    {  
        src_str.replace(pos,old_str_len,new_str);  
        pos+=new_str_len;  
        ++count;  
    }  
    return count;  
}   

ufilecsv::ufilecsv()
{
    memset(m_headline, 0, sizeof(m_headline));
}

ufilecsv::~ufilecsv()
{
    
}

void    ufilecsv::readhead()  
{  
    char strHeadLine[4096];

    m_CSVFile.getline(strHeadLine, sizeof(strHeadLine));

    if ((m_headline[0] != 0) && (strcmp(m_headline, strHeadLine) != 0))
    {
        parserow(m_headline, sizeof(m_headline), m_CSVHead);  
    }
    else
    {
        parserow(strHeadLine, sizeof(strHeadLine), m_CSVHead);  
    }
}  
  
void    ufilecsv::parserow(const char* strRow, int nSize, ROWVEC& result)  
{  
    result.clear();  
  
    bool    bIsInWord   = false;  
    bool    bIsHaveSpace = false;  
    string  strCurWorld;  
  
    for (int i=0; i<nSize; i++)  
    {  
        char ch = strRow[i];  
        if (ch == '\0')  
        {  
            if (i >= 1 && strRow[i-1] == ',')  
            {  
                strCurWorld = ' ';  
            }  
  
            break;  
        }  
  
        bool bIsAdd = true;  
  
        switch (ch)  
        {  
        case ',':  
            {  
                if (!bIsInWord)  
                {  
                    // 一项结束  
  
                    result.push_back(strCurWorld);  
  
                    bIsInWord   = false;  
                    bIsHaveSpace    = false;  
                    strCurWorld = "";  
  
                    bIsAdd  = false;  
                }  
            }  
            break;  
        case '"':  
            {  
                if (!bIsInWord)  
                {  
                    bIsInWord   = true;  
                    bIsHaveSpace    = true;  
  
                    bIsAdd  = false;  
                }  
                else  
                {  
                    if ('"' == strRow[i+1])  
                    {  
                        i++;  
                    }  
                    else if (bIsHaveSpace)  
                    {  
                        bIsInWord   = false;  
  
                        bIsAdd  = false;  
                    }  
                    else  
                    {  
                    }  
  
                }  
            }  
            break;  
        default:  
            //bIsInWord = true;  
            break;  
        };  
  
        if (bIsAdd)  
        {  
            strCurWorld += ch;  
        }  
  
    }  
  
    if (strCurWorld != "")  
    {  
        result.push_back(strCurWorld);  
    }  
  
}  

int     ufilecsv::findfield(const char* strRow)  
{  
    if (m_nFileState == FILE_STATE_NULL)  
    {
        return -1;  
    }  
  
    for (ROWVEC::iterator it = m_CSVHead.begin();  
        it != m_CSVHead.end(); it++)  
    {

        string buf = *it;
        char tem[50]={0};
        strcpy(tem,buf.c_str());

        if (*it == strRow)
        {
            return int(it - m_CSVHead.begin());  
        }  
    }  
    return -1;
}  
  
  
bool    ufilecsv::open(bool bIsRead, const char* strPath, const char* strFilename)  
{  
    m_nFileState    = FILE_STATE_NULL;  
    string strFullFileName(strPath);  
    strFullFileName += strFilename;  
	
    if (!bIsRead)
    {
        m_CSVFile.open(strFullFileName.c_str(), ios_base::out); 
        if (m_CSVFile.is_open())
        {
            m_CSVFile.close();
        }
    }
    
    m_CSVFile.open(strFullFileName.c_str(), ios_base::in); 
    
    if (!m_CSVFile.is_open())  
    {  
        return false;  
    }  
  
    readhead();  
  
    if (bIsRead)  
    {  
        m_nFileState    = FILE_STATE_READ;  
    }  
    else  
    {  
        m_nFileState    = FILE_STATE_WRITE;  
        m_CSVFile.close();  
        m_CSVFile.open(strFullFileName.c_str(), ios_base::out);  
        if (!m_CSVFile.is_open())  
        {  
            return false;  
        }  
  
        m_CSVCurRow = m_CSVHead;  
        setio();  
    }  
  
    return true;  
}  

bool    ufilecsv::close()  
{  
    m_nFileState    = FILE_STATE_NULL;  
  
    if (!m_CSVFile.is_open())  
    {  
        return true;  
    }  
    
    m_CSVFile.close();
  
    return true;  
}
  
// 读接口  
bool    ufilecsv::setio()  
{  
    if (m_nFileState == FILE_STATE_READ)  
    {  
        char strHeadLine[4096];
        
        if (m_CSVFile.eof())  
        {  
            return false;  
        }  
        
        m_CSVFile.getline(strHeadLine, sizeof(strHeadLine));  

        parserow(strHeadLine, sizeof(strHeadLine), m_CSVCurRow);  
    }
    else if (m_nFileState == FILE_STATE_WRITE)
    {
        for (ROWVEC::iterator it    = m_CSVCurRow.begin();  
        it != m_CSVCurRow.end(); it++)  
        {  
            string str = *it;  
            *it = "";  
            replace(str, "\"", "\"\"");  
      
            m_CSVFile << '"' << str << '"';  
            if (it + 1 != m_CSVCurRow.end())  
            {  
                m_CSVFile << ',';  
            }  
        }  
      
        m_CSVFile << endl;  
    }
    else
    {
        return false;
    }
    
    return true;  
}

bool    ufilecsv::sethead(const char* head)  
{  
    strcpy(m_headline, head);
    return true;  
}

