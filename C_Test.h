#pragma once
#include <iostream>
#include <fstream>
#include <string>
typedef std::string str;

class C_Test
{
private:
	/* ������ ������� � ������� ��� ������������� ������ ������ */
	std::string fileName = "File name";
	std:: fstream file;
public:
	void set_fileName(str &FileName) {
		fileName = FileName;
	}
	void get_fileName(str &container) {
		container = fileName;
	}
	void openFile() {
		file.open(fileName, std::ios_base::out | std::ios_base::app);
	}
	bool get_status() const /* ����������� ������� - �� ����� ������ �������� ������. ������ �������� �� */
	{
		return file.is_open();
	}
	void closeFile() {//��������� ����
		file.close();
	}
	void additional_recording(str &add_str) {//��������� ������
		file << add_str <<"\n";
	}
	int counter() {
		closeFile();
		file.open(fileName, std::ios::in);
		int counter_value = 0;
		std::string s;
		while (!file.eof()) {
			std::getline(file,s);
			counter_value++;
		}//������� peek ���������� ������, ������� ������ ���� �������� ��������� �������� ������ ������. � ���������, ��� ��������� ���������� ����� ������
		closeFile(); 
		return counter_value;
	}

	/* ������ ������� ��������� ������ �������� � �������� ��������� */
protected:
	/*������ �������, ��������� ��� ������������*/

};
