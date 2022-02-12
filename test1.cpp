#include <iostream>
#include "C_Test.h"
#include <string>

int main() {
	C_Test H;
	std::string H_answer;
	std::string FILEname = "base.txt";
	H.set_fileName(FILEname);
	H.get_fileName(H_answer);
	H.openFile();
	std::cout << H.get_status() << std::endl;
	std::cout << H_answer;
}