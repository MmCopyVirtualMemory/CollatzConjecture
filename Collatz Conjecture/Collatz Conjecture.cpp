#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string> 


bool IsEven(uint64_t input)
{
	return ((input % 2) == 0);
}

uint64_t ProcessEven(uint64_t input)
{
	return input / 2; 
}

uint64_t ProcessOdd(uint64_t input) 
{
	return ((input * 3) + 1);
}

int main()
{
	std::ofstream output_file;
	uint64_t current_number = 1;
	uint64_t current_instance = 0;
	std::vector<uint64_t> current_path = {};
	while (true) 
	{
		current_instance = current_number;	
		while (current_instance != 1)
		{
			if (IsEven(current_instance))
			{
				current_instance = ProcessEven(current_instance);
			}
			else 
			{
				current_instance = ProcessOdd(current_instance);
			}
			current_path.push_back(current_instance);
		}
		std::string current_file_number = std::to_string(current_number);
		output_file.open(current_file_number + ".txt");
		std::cout << current_number << std::endl;
		output_file << current_number;
		for (uint64_t i = 0; i < current_path.size(); i++) 
		{
			output_file << " -> " << current_path[i];
		}
		output_file.close();		
		current_number++;
		current_path.clear();
		//delete this if you do not want to contain the set of responses
		if (current_number > 20000) 
		{
			break;
		}
	}
}