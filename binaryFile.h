#ifndef __BINARYFILE_H__
#define __BINARYFILE_H__

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// typedef enum DEPARTMENT
// {
//     0,
//     1,
//     2,
//     3,
//     4    
// }DEP;

typedef struct employee
{
    int department;
    int employeeNum;
    char employeeName[30];
}EMP;


typedef struct departmentIndex
{
    //index
    int size;
}DepIndex;



//*********************START CLASS binaryFile DEFINITION*********************
class binaryFile
{
    public:
    /**************************** PUBLIC: Methods ****************************/
        binaryFile(string);
        ~binaryFile();
        bool search();
        void insert(string);
        EMP retrieve();
        void sort();
        bool update();
        void head(int);
    private:
    /**************************** PRIVATE: Variables ****************************/
        int records;
        string outputString;
        DepIndex fileIndexes[5];
    /**************************** PRIVATE: Methods ****************************/
        int p_Search();
        void p_Insert(string);
        EMP p_Retrieve();
        void p_Sort();
        bool p_Update();
        void p_SetRecords(int);
        int p_GetRecords();
        string p_GetOutputString();
        void p_SetOutputString(string);
        void p_head(int);
};
//*********************END CLASS binaryFile DEFINITION*********************

#endif