/*



*/


#include "ReadWriteFile.h"
#include "MyGlut.h"

#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAXBUFFER 512
#define NUM_OF_ROBOT_TARGET_PAIRS_INDEX 2
#define NUM_OF_OBJECTS_INDEX (3 + (6 * buffer[2])
#define NUM_OF_ROBOT_TARGET_PAIRS (buffer[NUM_OF_ROBOT_TARGET_PAIRS_INDEX])
#define NUM_OF_OBJECTS buffer[NUM_OF_OBJECTS_INDEX]
#define FIRST_OBJECT_RADIUS NUM_OF_OBJECTS_INDEX + 1
#define FIRST_PAIRS_RADIUS NUM_OF_ROBOT_TARGET_PAIRS_INDEX + 1 

ReadWriteFile* ReadWriteFile::RW_instance = nullptr;

//Creating singleton
ReadWriteFile * ReadWriteFile::getInstance()
{
	if (RW_instance == NULL)
	{
		RW_instance = new ReadWriteFile();

		return RW_instance;
	}
	else
	{
		return RW_instance;
	}
}

//Deleting singleton
void ReadWriteFile::releaseInstance()
{
	if (RW_instance != NULL)
	{
		delete RW_instance;
		RW_instance = NULL;
	}
}

//Function for opening and reading the ReadWriteFile
void ReadWriteFile::readFile()
{
	std::vector<int> inputFileLines;
	std::ifstream inputFile("env.txt");

	if (inputFile.is_open())
	{
		int line;
		while(inputFile >> line)
		{
			std::cout << "line : " << line << std::endl;
			inputFileLines.push_back(line); //add lines to the vector
		}
	}
	else
	{
		std::cerr << "Unable to open the file" << std::endl;
	}

	inputFile.close();

	//Check the vector
	std::cout << "stored Vector lines: " << std::endl;
	for (size_t i = 0; i < inputFileLines.size(); i++)
	{
		std::cout << "inputFileLines[" << i << "] :" << inputFileLines[i] << endl;
	}

	MyGlut::getInstance()->screenWidth = inputFileLines[0];
	MyGlut::getInstance()->screenHeight = inputFileLines[1];
}