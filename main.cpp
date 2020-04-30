#include "binaryFile.h"

int main(int argc, char** argv)
{
    binaryFile myFile("output.txt");

    myFile.insert("smallOutput.txt");
    myFile.sort();
    myFile.head(10);

    bool checkSearch = false;
    checkSearch = myFile.search(0,23);
    if (checkSearch == true)
        cout << "Employee Found" << endl;
    else
        cout << "Employee Not Found" << endl;

    char name[30] = "Me!"; 
    bool updateCheck = myFile.update(0,23,name);
    if(updateCheck)
        cout << "Employee Updated" << endl;;
    else
        cout << "Employee Not Updated" << endl;

    EMP* checkRetrieve;
    checkRetrieve = myFile.retrieve(0,23);
    cout << "Retrieved Name: " << checkRetrieve->employeeName << endl;
    cout << "Department: " << checkRetrieve->department << " Employee Number: " << checkRetrieve->employeeNum << endl;

    myFile.head(10);

    return 0;
}