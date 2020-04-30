#ifndef __BINARYFILE_H__
#define __BINARYFILE_H__

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct employee
{
    int department;
    int employeeNum;
    char employeeName[30];
}EMP;

typedef struct departmentIndex
{
    int start;
    int size;
}DepIndex;


//*********************START CLASS binaryFile DEFINITION*********************
class binaryFile
{
    public:
    /**************************** PUBLIC: Methods ****************************/
        binaryFile(string);
        ~binaryFile();
        bool search(int, int);
        void insert(string);
        EMP* retrieve(int, int);
        void sort();
        bool update(int, int, string);
        void head(int);
        
    private:
    /**************************** PRIVATE: Variables ****************************/
        int records;
        string outputString;
        DepIndex fileIndexes[5];
    /**************************** PRIVATE: Methods ****************************/
        int p_Search(int, int);
        void p_Insert(string);
        EMP* p_Retrieve(int, int);
        void p_Sort();
        void p_SetRecords(int);
        int p_GetRecords();
        string p_GetOutputString();
        void p_SetOutputString(string);
        void p_head(int);
        bool p_Update(int, int, string);
};
//*********************END CLASS binaryFile DEFINITION*********************

#endif