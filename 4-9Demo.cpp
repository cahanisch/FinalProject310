#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct coord
{
    int x;
    int y;
    int z;
}S_COORD;

int main(int argc, char** argv)
{
    ifstream inputData;
    fstream outputData;
    string inputFileName = "coordinates.txt";
    string inputLine;
    int numLines = 0;
    S_COORD *dataArray;
    int commaArray[3] = {0};
    int i = 0;

    inputData.open(inputFileName);

    if(inputData.is_open())
    {
        while(getline(inputData, inputLine))
        {
            numLines++;
        }
        dataArray = new S_COORD[numLines];
        inputData.clear();
        inputData.seekg(0, ios::beg);

        while(getline(inputData, inputLine))
        {
            commaArray[0] = inputLine.find(",");
            commaArray[1] = inputLine.find(",", commaArray[0] + 1);
            commaArray[2] = inputLine.find(",", commaArray[1] + 1);

            dataArray[i].x = atoi(inputLine.substr(0, commaArray[0]).c_str);
            dataArray[i].y = atoi(inputLine.substr(commaArray[0], commaArray[1]).c_str);
            dataArray[i].z = atoi(inputLine.substr(commaArray[1], commaArray[2]).c_str);

            i++;
        }
        inputData.close();
    }

    outputData.open("binary_coordinates.txt", ios::out|ios::binary);

    if(outputData.is_open())
    {
        outputData.write((char*)dataArray, sizeof(S_COORD)*numLines);
        outputData.close();
    }

    delete[] dataArray;

    return 0;
}