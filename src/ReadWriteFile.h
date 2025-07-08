/*



*/




#ifndef READWRITEFILE_H_
#define READWRITEFILE_H_

class ReadWriteFile
{
	private:
		int* buffer;
		struct stat * statBuff;
		static ReadWriteFile * RW_instance;
		ReadWriteFile() {}

	public:
		static ReadWriteFile * getInstance();
		static void releaseInstance();
		void readFile();
		int get_buffer(int index) {return buffer[index];}
};

#endif