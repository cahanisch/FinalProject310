#ifndef __BINARYFILE_H__
#define __BINARYFILE_H__

#include <iostream>
#include <string>
#include <fstream>

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
    string employeeName;
}EMP;

//*********************START CLASS binaryFile DEFINITION*********************
class binaryFile
{
    public:
    /**************************** PUBLIC: Methods ****************************/
        binaryFile();
        ~binaryFile();
        bool search();
        void insert(string);
        EMP retrieve();
        void sort();
        bool update();
    private:
    /**************************** PRIVATE: Variables ****************************/
        fstream file;
        int records;
        EMP* dataArray;
    /**************************** PRIVATE: Methods ****************************/
        int p_Search();
        void p_Insert(string);
        EMP p_Retrieve();
        void p_Sort();
        bool p_Update();
        void p_SetRecords(int);
        int p_GetRecords();
};
//*********************END CLASS binaryFile DEFINITION*********************

#endif