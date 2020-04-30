#include "binaryFile.h"

//TODO: add libary for custom exception handling

binaryFile::binaryFile(string outFile)
{
    this->records = 0;
    this->outputString = outFile;

    for(int i = 0; i < 5; i++)
    {
        fileIndexes[i].size = 0;
        fileIndexes[i].start = 0;
    }
}
binaryFile::~binaryFile()
{

}
bool binaryFile::search(int dep, int empNum)
{
    int found = this->p_Search(dep, empNum);

    // There's probably an exception handling way to deal with this chunk. if the value comes back as -1 it was not found
    if (found == -1)
        return false;
    else
        return true;
}
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
EMP* binaryFile::retrieve(int dep, int empNum)
{
    bool exists = this->search(dep, empNum);
    EMP* employeeToFind = NULL;
    if (exists)
    {
        employeeToFind = this->p_Retrieve(dep, empNum);
	}
//    else
        return employeeToFind;
}
void binaryFile::sort()
{
    this->p_Sort();
}

bool binaryFile::update(int dep, int empNum, char newName[])
{
	bool exists = this->search(dep, empNum);
    EMP* employeeToFind = NULL;
    char temp[30];
    fstream fp;
    fp.open("output.txt", ios::in|ios::binary);
    if (exists)
    {
        employeeToFind = this->p_Retrieve(dep, empNum);
		if (employeeToFind == NULL)
        {
            fp.close();
			return false;
        }
		else
        {
		    strncpy(temp, employeeToFind->employeeName, 30);
		    strncpy(employeeToFind->employeeName, newName, 30);
            //TODO write back out to file
            cout << "Test: " << employeeToFind->employeeName << endl;
			if (employeeToFind->employeeName == temp)
            {
                fp.close();
				return false;
            }
			else
            {
                fp.close();	
				return true;
            }
		
		}
	
	}
    else
    {
        fp.close();
        return false;
    }
    
    
    fp.open("output.txt", ios::out|ios::binary); 
    fp.seekp(sizeof(EMP)*p_Search(dep, empNum));
	if(fp.is_open())
    {
        fp.write((char*)employeeToFind, sizeof(EMP));
        fp.close();
    
	}
    
}

void binaryFile::head(int n)
{
    //make sure n is less than or equal to number of records
    this->p_head(n);
}
int binaryFile::p_Search(int dep, int empNum)
{
    int offset = -1;
    fstream fp;
    int i;
    int i_dep, i_empNum;
    fp.open("output.txt", ios::in|ios::binary); 
    EMP buff;

    if(fp.is_open())
    {    
        for(i = 0; i < this->records; i++)
        {
            // read in a sizeof EMP, grab that record's department number and employee number, then compare it.
            fp.read((char*)&buff, sizeof(EMP));
            i_dep = buff.department;
            i_empNum = buff.employeeNum;
            // if the department and number are a match, we know it was found and we know its offset
            if (i_dep == dep && i_empNum == empNum)
            {
                // i = the offset to the record
                offset = i;
                // cause a loop termination, we're at the end of what we need
                i = this->records;
			}
        }

        fp.close();
    }

    return offset;
}
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
EMP* binaryFile::p_Retrieve(int dep, int empNum)
{
    // Repeated code from Search function
    fstream fp;
    int i;
    int i_dep, i_empNum;
    int counter = p_GetRecords();
    fp.open("output.txt", ios::in|ios::binary); 
    EMP buff;
    EMP* employeeReturn = new EMP;

    if(fp.is_open())
    {    
        for(i = 0; i < counter; i++)
        {
            // read in a sizeof EMP, grab that record's department number and employee number, then compare it.
            fp.read((char*)&buff, sizeof(EMP));
            i_dep = buff.department;
            i_empNum = buff.employeeNum;
            // if the department and number are a match, we know it was found and we know its offset
            if (i_dep == dep && i_empNum == empNum)
            {
                // Fill out the information to send back
                employeeReturn->department = buff.department;
                employeeReturn->employeeNum = buff.employeeNum;
                strncpy(employeeReturn->employeeName, buff.employeeName, 30);
			}
        }

        fp.close();
    }

    return employeeReturn;

}

//still to do: 
//create the indexes!
void binaryFile::p_Sort()
{

    //make the bins
    EMP *separatedDepartments[5];
    int departmentSizeCounter[5] = {0};
    int i, dep, k;
    int counter = this->p_GetRecords();
    for(i = 0; i < 5; i++)
    {
        separatedDepartments[i] = new EMP [fileIndexes[i].size];

        if(i!=0)
        {
            fileIndexes[i].start = fileIndexes[i-1].start + fileIndexes[i-1].size;
        }

    }

    //read record from file and put in respective bin
    fstream fp;
    //fp.open(this->outputString, ios::in|ios::binary)

    fp.open("output.txt", ios::in|ios::binary); //to compile on tylers compiler
    EMP buff;

    if(fp.is_open())
    {    
        for(i = 0; i < counter; i++)
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
/*
bool binaryFile::p_Update(int dep, int empNum, char newName[])
{
	fstream fp;
    int i;
    int i_dep, i_empNum;
    int counter = p_GetRecords();
    fp.open("output.txt", ios::in|ios::binary); 
    EMP buff;
    EMP* employeeReturn = new EMP;
	if(fp.is_open())
    {    
        for(i = 0; i < counter; i++)
        {
            
            fp.read((char*)&buff, sizeof(EMP));
            i_dep = buff.department;
            i_empNum = buff.employeeNum;
            
            if (i_dep == dep && i_empNum == empNum)
            {
            
                employeeReturn->department = buff.department;
                employeeReturn->employeeNum = buff.employeeNum;
                strncpy(employeeReturn->employeeName, buff.employeeName, 30);
			}
        }
        fp.close();
    }
    return employeeReturn;
}
*/

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
