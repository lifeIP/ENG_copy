#pragma once
#include <iostream>
#include <fstream>
#include <string>
typedef std::string str;

class C_Test
{
private:
	/* список свойств и методов для использования внутри класса */
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
	bool get_status() const /* Константная функция - не может менять атрибуты класса. Только получать их */
	{
		return file.is_open();
	}
	void closeFile() {//Закрывает файл
		file.close();
	}
	void additional_recording(str &add_str) {//Добавляет записи
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
		}//Функция peek возвращает символ, который должен быть прочитан следующей функцией чтения потока. В частности, это позволяет распознать конец потока
		closeFile(); 
		return counter_value;
	}

	/* список методов доступных другим функциям и объектам программы */
protected:
	/*список средств, доступных при наследовании*/

};
