#ifndef __BINARYFILE_H__
#define __BINARYFILE_H__

#include <iostream>
#include <string>
#include <fstream>

typedef enum DEPARTMENT
{
    0,
    1,
    2,
    3,
    4    
}DEP;

typedef struct employee
{
    int department;
    int employeeName;
    string employeeName;
}EMP;

using namespace std;

//*********************START CLASS binaryFile DEFINITION*********************
class binaryFile
{
    public:
    /**************************** PUBLIC: Methods ****************************/
        bool search();
        void insert();
        EMP retrieve();
        void sort();
        bool update();
    private:
    /**************************** PRIVATE: Variables ****************************/
        
    /**************************** PRIVATE: Methods ****************************/
        int p_Search();
        void p_Insert();
        EMP p_Retrieve();
        void p_Sort();
        bool p_Update();
};
//*********************END CLASS rbTree DEFINITION*********************

#endif