/*



*/


#include "ReadWriteFile.h"
#include "MyGlut.h"
#include "Simulation.h"

#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

//****These values are calculations to determine the proper Indeces*******
#define MAXBUFFER 512
#define NUM_OF_OBJECTS_INDEX buffer[2]
#define NUM_OF_ROBOT_TARGET_PAIRS_INDEX 2
#define NUM_OF_ROBOT_TARGET_PAIRS (buffer[NUM_OF_ROBOT_TARGET_PAIRS_INDEX])
#define NUM_OF_OBJECTS (buffer[NUM_OF_OBJECTS_INDEX])
#define FIRST_OBJECT_RADIUS NUM_OF_OBJECTS_INDEX + 1
#define FIRST_PAIRS_RADIUS NUM_OF_ROBOT_TARGET_PAIRS_INDEX + 1
//************************************************************************

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
	/*
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
		std::cout << "inputFileLines[" << i << "] :" << inputFileLines[i] << std::endl;
	}
	*/
	//allocate an int array of MAXBUFFER size 
	buffer = (int*)malloc(sizeof(int) * MAXBUFFER);
	int fd;
	size_t bytes_read;

	//open target file ReadOnly
	fd = open("env.txt", O_RDONLY);

	//read target file into buffer
	bytes_read = read(fd, buffer, MAXBUFFER);

	//close the file discriptor
	//close(fd);
	//************************************************************

	//int num1[5];

	ifstream bfile;

	bfile.open("env.txt");

	unsigned int index = 0;

	if (bfile.is_open())
	{
		while (index <= bytes_read)
		{
			bfile >> buffer[index];

			cout << "buffer[" << index << "]" << " equals " << buffer[index] << endl;

			index++;
		}
	}

	bfile.close();

	/*if ((fd = open("env.txt", O_RDONLY)) == -1)
	{
		perror("file open failed.");
		fprintf(stderr, "err = %d: %s\n", errno, strerror(errno));
	}

	if ((bytes_read = read(fd, buffer, MAXBUFFER)) == -1)
	{
		perror("failed to ready the file.");
		fprintf(stderr, "err = %d: %s\n", errno, strerror(errno));
	}*/

	cout << "here" << endl;

	MyGlut::getInstance()->screenWidth = buffer[0];
	MyGlut::getInstance()->screenHeight = buffer[1];

	//set the number of objects in Simulation to following and pass the array index of that value
	Simulation::getInstance()->set_ObjectInfo(NUM_OF_OBJECTS, FIRST_OBJECT_RADIUS);//6 , index 21
}