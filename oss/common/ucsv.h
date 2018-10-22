#pragma once
#include <qdebug.h>
#include "upub.h"


typedef vector<string> ROWVEC;  

enum  
{  
    FILE_STATE_NULL,  
    FILE_STATE_READ,  
    FILE_STATE_WRITE,  
};  

class ufilecsv  
{  
public:  
    ufilecsv();
    ~ufilecsv();
    bool    open(bool bIsRead, const char* strPath, const char* strFilename);  
    bool    close();
    bool    setio();
    bool    sethead(const char* head);

    // 读接口  
    template<class T>  
    bool    read(const char* strFieldName, T& data)  
    {  
        if (m_nFileState != FILE_STATE_READ)  
        {  
            return false;  
        }  
  
        int n   = findfield(strFieldName);
        if (n == -1 || n >= m_CSVCurRow.size())  
        {  
            return false;  
        }  

        /*can't support string which contains space, so add readstring()*/
        stringstream ss;  
        ss << m_CSVCurRow[n];  
        ss >> data;  
  
        return true;  
    }  
  
    // 写接口  
    template<class T>  
    bool    write(const char* strFieldName, T data)  
    {  
        if (m_nFileState != FILE_STATE_WRITE)  
        {  
            return false;  
        }  
  
        int n   = findfield(strFieldName);  
        if (n == -1)  
        {  
            return false;  
        }  
        
        /*can't support string which contains space, so add writestring()*/
        stringstream ss;  
        ss << data;  
        m_CSVCurRow[n]  = ss.str();  
  
        return true;  
    }  

    bool    readstring(const char* strFieldName, char* data, int size)  
    {  
        if (m_nFileState != FILE_STATE_READ)  
        {  
            return false;  
        }  
  
        int n   = findfield(strFieldName);  
        if (n == -1 || n >= m_CSVCurRow.size())  
        {  
            return false;  
        }  
  
        strncpy(data, m_CSVCurRow[n].data(), size-1);
  
        return true;  
    }  

    bool    writestring(const char* strFieldName, char* data, int size)  
    {  
        if (m_nFileState != FILE_STATE_WRITE)  
        {  
            return false;  
        }  
  
        int n   = findfield(strFieldName);  
        if (n == -1)  
        {  
            return false;  
        }  

        m_CSVCurRow[n]  = data;  
  
        return true;  
    }  

private:  
    void    readhead();  
    void    parserow(const char* strRow, int nSize, ROWVEC& result);  
    int     findfield(const char* strRow);  
  
private:  
    int         m_nFileState;  
    fstream     m_CSVFile;  
    ROWVEC      m_CSVHead;  
    ROWVEC      m_CSVCurRow;  

    char        m_headline[4096];
};  
  

