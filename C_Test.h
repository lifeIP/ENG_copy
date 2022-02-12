#pragma once
#include <iostream>
#include <fstream>
#include <string>
typedef std::string str;

class C_Test
{
private:
	/* ������ ������� � ������� ��� ������������� ������ ������ */
	std::string fileName = "base.txt";
	std::string sortFile = "sorter.txt";
	std:: fstream file;
public:
	void set_fileName(str &FileName) {
		fileName = FileName;
	}
	void get_fileName(str &container) {
		container = fileName;
	}
	void closeFile() {//��������� ����
		file.close();
	}
	void additional_recording(str &add_str) {//��������� ������
		closeFile();
		while (!file.is_open()) {
			file.open(fileName, std::ios_base::out | std::ios_base::app);
		}
		file << add_str <<"\n";
		closeFile();
	}
	int counter() {
		closeFile();
		while (!file.is_open()) {
			file.open(fileName);
		}
		int counter_value = 0;
		str s;
		while (file.peek()!=EOF) {
			std::getline(file,s);
			counter_value++;
		}//������� peek ���������� ������, ������� ������ ���� �������� ��������� �������� ������ ������. � ���������, ��� ��������� ���������� ����� ������
		closeFile(); 
		return counter_value;
	}
	void doCopyFile(str &file1, str endfile) {
		std::fstream fileSource;
		std::fstream fileFinite;
		fileSource.open(file1);
		fileFinite.open(endfile, std::ios::in | std::ios::app);
		str copy_text;
		while (fileSource.peek() != EOF) {
			std::getline(fileSource, copy_text);
			fileFinite << copy_text<<"\n";
		}
		fileSource.close();
		fileFinite.close();
	}
	bool sorting() {
		std::fstream sorter;
		sorter.open(sortFile, std::ios::out |std::ios::trunc);
		sorter.close();
		while (!sorter.is_open()) {
			sorter.open(sortFile, std::ios::in | std::ios::app );
		} 
		doCopyFile(fileName, sortFile);
		
		sorter.close();
		return true;
	}


	/* ������ ������� ��������� ������ �������� � �������� ��������� */
protected:
	/*������ �������, ��������� ��� ������������*/

};
