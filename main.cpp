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

    return 0;
}