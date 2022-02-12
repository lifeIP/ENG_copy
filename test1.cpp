#include "C_Test.h"

int main() {
	C_Test H;
	std::string H_answer;
	std::string FILEname = "base.txt";
	H.set_fileName(FILEname);
	H.get_fileName(H_answer);
	H.additional_recording(FILEname);
	std::cout << H_answer;
	int s;
	s = H.counter();
	std::cout << "\n\n" << s;
	bool b;
	b = H.sorting();
	std::cout << "\n\n" << b;
}