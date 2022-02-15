#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::string str;

class C_Test
{
private:
	/* ������ ������� � ������� ��� ������������� ������ ������ */
	std::string fileName = "base.txt";
	std::string sortFile = "sorter.txt";

public:
	/*������ ���������� ������������� ������*/
	C_Test();//��� �������� ��������������� ����� 
	C_Test(str& someString);//��� ���������� ������� 
	C_Test(str& file1, str& endfile);//��� ���������� ����������� ������� 
	/*����� ���������� ������������� ������*/

	void set_fileName(str& FileName, str& sort_file_name) {
		fileName = FileName;
		sortFile = sort_file_name;
	}

	void get_fileName(str& filename, str& sort_file_name) {
		filename = fileName;
		sort_file_name = sortFile;
	}

	void additional_recording(str& add_str) {//��������� ������
		std::fstream file;
		while (!file.is_open()) {
			file.open(fileName, std::ios_base::out | std::ios_base::app);
		}
		file << add_str << "\n";
		file.close();
	}

	int counter() {
		std::fstream file;
		while (!file.is_open()) {
			file.open(fileName);
		}
		int counter_value = 0;
		str s;
		while (file.peek() != EOF) {
			std::getline(file, s);
			counter_value++;
		}//������� peek ���������� ������, ������� ������ ���� �������� ��������� �������� ������ ������. � ���������, ��� ��������� ���������� ����� ������
		file.close();
		return counter_value;
	}

	void doCopyFile(str& file1, str endfile) {
		std::fstream fileSource;
		std::fstream fileFinite;
		fileSource.open(file1);
		fileFinite.open(endfile, std::ios::in | std::ios::app);
		str copy_text;
		while (fileSource.peek() != EOF) {
			std::getline(fileSource, copy_text);
			fileFinite << copy_text << "\n";
		}
		fileSource.close();
		fileFinite.close();
	}
	void doSorting(str& file1, str& file2) {
		std::ifstream in(file1);
		std::vector<str> vs;
		str ss;
		while (getline(in, ss)) vs.push_back(ss);
		sort(vs.begin(), vs.end());
		std::ofstream on(file2);
		copy(vs.begin(), vs.end(), std::ostream_iterator<str>(on, "\n"));
		in.close();
		on.close();
	}

	void sorting() {
		std::fstream file;
		std::fstream sorter;
		sorter.open(sortFile, std::ios::out | std::ios::trunc);
		sorter.close();
		doSorting(fileName, sortFile);
	}
	~C_Test() {}
	/* ������ ������� ��������� ������ �������� � �������� ��������� */
protected:
	/*������ �������, ��������� ��� ������������*/

};
C_Test::C_Test() {//��� �������� ��������������� ����� 
	sorting();
}
C_Test::C_Test(str& someString) {//��� ���������� ������� 
	additional_recording(someString);
}
C_Test::C_Test(str& file1, str& endfile) {//��� ���������� ����������� ������� 
	doCopyFile(file1, endfile);
}