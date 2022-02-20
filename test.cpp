#include "root.h"
#include <string>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	std::string file1 = "base.txt";
	std::string file2 = "base2.txt";
	std::string file3 = "base3.txt";
	std::string file4 = "base4.txt";
	int n = 0;
	std::string some_info;
	while (true) {
		std::cout << "---> ";
		getline(std::cin, some_info);
		if (some_info == "0") break;
		additional_recording(file1, some_info);
	}
	doSorting(file1, file2);
	std::cout << n;
	dataParser(file3, file4);
}