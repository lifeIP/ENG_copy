#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

typedef std::string str;

void doSorting(str& file1, str& file2) {
	std::fstream file;
	std::fstream sorter;
	sorter.open(file2);
	sorter.close();
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

void additional_recording(str& fileName, str& add_str) {//Добавляет записи
	std::fstream file;
	while (!file.is_open()) {
		file.open(fileName, std::ios_base::out | std::ios_base::app);
	}
	file << add_str << "\n";
	file.close();
}

void counter(str& fileName, int& res) {
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
	res = counter_value;
}

void doCopyFile(str& file1, str file2) {
	std::fstream fileSource;
	std::fstream fileFinite;
	fileSource.open(file1);
	fileFinite.open(file2, std::ios::in | std::ios::app);
	str copy_text;
	while (fileSource.peek() != EOF) {
		std::getline(fileSource, copy_text);
		fileFinite << copy_text << "\n";
	}
	fileSource.close();
	fileFinite.close();
}


void dataParser(str& file1, str& file2) {
	std::fstream fileSource;
	std::fstream fileFinite;
	fileSource.open(file1);
	fileFinite.open(file2, std::ios::in | std::ios::app);
	str copy_text_1;
	str copy_text_2;
	str copy_text_3;
	while (fileSource.peek() != EOF) {
		std::getline(fileSource, copy_text_1, '[');
		std::getline(fileSource, copy_text_2, ']');
		std::getline(fileSource, copy_text_3);
		fileFinite << copy_text_1 + "###" + copy_text_3 + "###" + copy_text_2 + "\n";
	}	
	fileSource.close();
	fileFinite.close();
}