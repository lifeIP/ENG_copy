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
	/* список свойств и методов для использования внутри класса */
	std::string fileName = "base.txt";
	std::string sortFile = "sorter.txt";

public:
	/*Начало объявления конструкторов класса*/
	C_Test();//Для создания отсортированной копии 
	C_Test(str& someString);//Для добавления записей 
	C_Test(str& file1, str& endfile);//Для резервного копирования записей 
	/*Конец объявления конструкторов класса*/

	void set_fileName(str& FileName, str& sort_file_name) {
		fileName = FileName;
		sortFile = sort_file_name;
	}

	void get_fileName(str& filename, str& sort_file_name) {
		filename = fileName;
		sort_file_name = sortFile;
	}

	void additional_recording(str& add_str) {//Добавляет записи
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
		}//Функция peek возвращает символ, который должен быть прочитан следующей функцией чтения потока. В частности, это позволяет распознать конец потока
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
	/* список методов доступных другим функциям и объектам программы */
protected:
	/*список средств, доступных при наследовании*/

};
C_Test::C_Test() {//Для создания отсортированной копии 
	sorting();
}
C_Test::C_Test(str& someString) {//Для добавления записей 
	additional_recording(someString);
}
C_Test::C_Test(str& file1, str& endfile) {//Для резервного копирования записей 
	doCopyFile(file1, endfile);
}