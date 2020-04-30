#include "binaryFile.h"

int main(int argc, char** argv)
{
    binaryFile myFile("output.txt");

    myFile.insert("smallOutput.txt");
    myFile.sort();
    myFile.head(20);

    bool checkSearch;
    checkSearch = myFile.search(0,23);
    if (checkSearch == true)
        cout << "Search works" << endl;
    else
        cout << "Search didnt' work :( " << endl;


    char name[30] = "Me!"; 
    if(myFile.update(0, 23, name))
    {
        cout << "updated\n";
    }

    EMP* checkRetrieve;
    checkRetrieve = myFile.retrieve(0,23);
    cout << "Retrieved Name: " << checkRetrieve->employeeName << endl;
    cout << "Department: " << checkRetrieve->department << " Employee Number: " << checkRetrieve->employeeNum << endl;

    myFile.head(10);


    return 0;
}