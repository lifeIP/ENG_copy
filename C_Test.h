#pragma once
#include <iostream>
#include <fstream>
#include <string>

class C_Test
{
private:
	/* ������ ������� � ������� ��� ������������� ������ ������ */
	std::string fileName = "File name";
	std:: fstream file;
public:
	void set_fileName(std::string &FileName) {
		fileName = FileName;
	}
	void get_fileName(std::string &container) {
		container = fileName;
	}
	void openFile() {
		file.open(fileName);
	}
	bool get_status() const /* ����������� ������� - �� ����� ������ �������� ������. ������ �������� �� */
	{
		return file.is_open();
	}
	void additional_recording() {
		
	}

	/* ������ ������� ��������� ������ �������� � �������� ��������� */
protected:
	/*������ �������, ��������� ��� ������������*/

};
