#include "binaryFile.h"

int main(int argc, char** argv)
{
    binaryFile myFile("output.txt");

    myFile.insert("smallOutput.txt");
    myFile.sort();
    myFile.head(20);

    bool checkSearch;
    checkSearch = myFile.search(0,45731);
    if (checkSearch == true)
        cout << "Search works" << endl;
    else
        cout << "Search didnt' work :( " << endl;
    
    myFile.update(0, 45731, "ME!");

    EMP* checkRetrieve;
    checkRetrieve = myFile.retrieve(0,45731);
    cout << "Retrieved Name: " << checkRetrieve->employeeName << endl;
    cout << "Department: " << checkRetrieve->department << " Employee Number: " << checkRetrieve->employeeNum << endl;

    char newName[30] = "Bob";
    myFile.update(0, 45731, newName);

    EMP* checkRetrieve2;
    checkRetrieve2 = myFile.retrieve(0,45731);
    cout << "Retrieved Name: " << checkRetrieve2->employeeName << endl;
    cout << "Department: " << checkRetrieve2->department << " Employee Number: " << checkRetrieve2->employeeNum << endl;

    return 0;
}