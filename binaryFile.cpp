#include "binaryFile.h"
//TODO: add libary for custom exception handling

binaryFile::binaryFile()
{
    this->records = 0;
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
// void binaryFile::sort()
// {

// }
// bool binaryFile::update()
// {

// }
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

    inputData.open(inputFile);

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
            dataArray[recordCount].employeeName = inputLine.substr(commaArray[1] + 1, commaArray[2]).c_str();

            recordCount++;
        }
        inputData.close();
    }
    outputData.open("output.txt", ios::out|ios::binary);

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
// void binaryFile::p_Sort()
// {

// }
// bool binaryFile::p_Update()
// {

// }
int binaryFile::p_GetRecords()
{
    return this->records;
}
void binaryFile::p_SetRecords(int recordNum)
{
    this->records = recordNum;
}