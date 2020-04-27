#include "binaryFile.h"

int main(int argc, char** argv)
{
    binaryFile myFile("output.txt");

    myFile.insert("smallOutput.txt");
    myFile.sort();
    myFile.head(20);

    return 0;
}