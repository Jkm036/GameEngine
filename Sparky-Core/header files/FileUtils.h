#pragma once
#include<string>
#include<iostream>

namespace Sparky {
	class FileUtils {
	public:
		static std::string read_file(const char* file_path) {
	
			FILE* file;
			if((file = fopen(file_path, "rt"))) {
					//go to end of file
					fseek(file, 0, SEEK_END);
					//Get the current position  in file (Currently the end)
					unsigned long length = ftell(file);
					//Data where we will store file info
					char* data = new char[length + 1] {0};
					//setting all of data to nul byte
					//memset(data, 0, length + 1);
					// go back to beginning of file
					fseek(file, 0, SEEK_SET);
					//read file into data
					fread(data, 1, length, file);
					//close file
					fclose(file);
					//create a string with data result
					std::string result(data);
					//delete memory in heap
					delete[] data;
					return result;
			}else {
				std::cout << "File couldn't be opened: " << std::endl;
				std::cout << file_path << std::endl;
			}
			

		}

	};

}