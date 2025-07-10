/*



*/





#include <stdio.h>
#include <iostream>
#include <fstream>

#include "ReadWriteFile.h"
#include "MyGlut.h"


using namespace std;

int main (int argc, char ** argv)
{
	//printf("Entering main \n");
	cout << "Entering main\n";

	ReadWriteFile::getInstance()->readFile();

	MyGlut::getInstance()->init(argc, argv);

	//printf("Leaving main\n");
	cout << "Leaving main\n";

	return 0;
}