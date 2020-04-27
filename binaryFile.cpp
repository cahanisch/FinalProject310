#include "binaryFile.h"

//TODO: add libary for custom exception handling

binaryFile::binaryFile(string outFile)
{
    this->records = 0;
    this->outputString = outFile;

    for(int i = 0; i < 5; i++)
    {
        fileIndexes[i].size = 0;
    }
}
binaryFile::~binaryFile()
{

}
// bool binaryFile::search()
// {

// }
void binaryFile::insert(string fileName)
{
    //try
    //{
        this->p_Insert(fileName);   
    //}
    /*
    catch(MyException &exc)
    {
        cerr << exc.what() << endl;
    }
    */
}
// EMP binaryFile::retrieve()
// {

// }
void binaryFile::sort()
{
    this->p_Sort();
}
// bool binaryFile::update()
// {

// }

void binaryFile::head(int n)
{
    //make sure n is less than or equal to number of records
    this->p_head(n);
}
// int binaryFile::p_Search()
// {

// }
void binaryFile::p_Insert(string inputFile)
{
    ifstream inputData;
    fstream outputData;
    string inputLine;
    int numLines = 0;
    EMP* dataArray;
    int commaArray[3] = {0};
    int recordCount = this->p_GetRecords();
    string outFile = this->p_GetOutputString();

    //inputData.open(inputFile);


    inputData.open("smallOutput.txt"); //to work on tylers compiler

    if(inputData.is_open())
    {
        while(getline(inputData, inputLine))
        {
            numLines++;
        }
        dataArray = new EMP[numLines];
        inputData.clear();
        inputData.seekg(0, ios::beg);

        while(getline(inputData, inputLine))
        {
            commaArray[0] = inputLine.find(",");
            commaArray[1] = inputLine.find(",", commaArray[0] + 1);
            commaArray[2] = inputLine.find(",", commaArray[1] + 1);

            dataArray[recordCount].department = atoi(inputLine.substr(0, commaArray[0]).c_str());
            dataArray[recordCount].employeeNum = atoi(inputLine.substr(commaArray[0] + 1, commaArray[1]).c_str());
            strncpy(dataArray[recordCount].employeeName,  inputLine.substr(commaArray[1] + 1, commaArray[2]).c_str(), 30);

            fileIndexes[dataArray[recordCount].department].size++; //increment department size

            recordCount++;
        }
        inputData.close();
    }
    //outputData.open(outFile, ios::out|ios::binary);

    outputData.open("output.txt", ios::out|ios::binary); //to work on tylers compiler

    if(outputData.is_open())
    {
        outputData.write((char*)dataArray, sizeof(EMP)*numLines);
        outputData.close();
    }

    this->p_SetRecords(recordCount);

    delete[] dataArray;



}   
// EMP binaryFile::p_Retrieve()
// {

// }

//still to do: 
//create the indexes!
//(maybe) add a sort 
void binaryFile::p_Sort()
{

    //make the bins
    EMP *separatedDepartments[5];
    int departmentSizeCounter[5] = {0};
    int i, dep, k;
    for(i = 0; i < 5; i++)
    {
        separatedDepartments[i] = new EMP [fileIndexes[i].size];
    }

    //read record from file and put in respective bin
    fstream fp;
    //fp.open(this->outputString, ios::in|ios::binary)

    fp.open("output.txt", ios::in|ios::binary); //to compile on tylers compiler
    EMP buff;

    if(fp.is_open())
    {    
        for(i = 0; i < this->records; i++)
        {

            fp.read((char*)&buff, sizeof(EMP));
            dep = buff.department;
            k = departmentSizeCounter[dep];
            separatedDepartments[dep][k] = buff;


            departmentSizeCounter[dep]++;
        }

        fp.close();
    }

    //write the bins back to the file


    //fp.open(this->outputString, ios::out|ios::binary);
    fp.open("output.txt", ios::out|ios::binary); //to compile on tylers compiler
    if(fp.is_open())
    {
        for(i = 0; i < 5; i++)
        {
            k = departmentSizeCounter[i];
            fp.write((char*)separatedDepartments[i], sizeof(EMP)*k);

            delete[] separatedDepartments[i];
        }
        fp.close();
    }

    

    
}
// bool binaryFile::p_Update()
// {

// }


//prints out first n items
void binaryFile::p_head(int n)
{
    fstream fp;
    fp.open("output.txt", ios::in|ios::binary); //to compile on tylers compiler
    int i;
    EMP buff;

    for(i = 0; i < n; i++)
    {
        fp.read((char*)&buff, sizeof(EMP));
        
        cout << buff.department << " ";
        cout << buff.employeeNum << " ";
        cout << buff.employeeName << endl;

    }
}

int binaryFile::p_GetRecords()
{
    return this->records;
}
void binaryFile::p_SetRecords(int recordNum)
{
    this->records = recordNum;
}
string binaryFile::p_GetOutputString()
{
    return this->outputString;
}
void binaryFile::p_SetOutputString(string outFile)
{
    this->outputString = outFile;
}