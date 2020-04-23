#include "binaryFile.h"
//TODO: add libary for custom exception handling

binaryFile::binaryFile()
{

}
binaryFile::~binaryFile()
{

}
bool binaryFile::search()
{

}
void binaryFile::insert()
{
    
}
EMP binaryFile::retrieve()
{

}
void binaryFile::sort()
{

}
bool binaryFile::update()
{

}
int binaryFile::p_Search()
{

}
void binaryFile::p_Insert()
{
    ifstream inputData;
    string inputFile = "smallOutput.txt";
    string inputLine;
    int numLines = 0;
    EMP* dataArray;
    int commaArray[3] = {0};
    int i = 0;

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

            dataArray[i].department = atoi(inputLine.substr(0, commaArray[0]).c_str);
            dataArray[i].employeeNum = atoi(inputLine.substr(commaArray[0], commaArray[1]).c_str);
            dataArray[i].employeeName = atoi(inputLine.substr(commaArray[1], commaArray[2]).c_str);

            i++;
        }
        inputData.close();
    }
}
EMP binaryFile::p_Retrieve()
{

}
void binaryFile::p_Sort()
{

}
bool binaryFile::p_Update()
{

}