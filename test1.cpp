#include "C_Test.h"

int main() {
	setlocale(LC_ALL, "rus");
	std::string file;
	while (true) {
		std::cin >> file;
		C_Test H(file);
	}
}