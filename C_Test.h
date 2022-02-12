#pragma once
#include <iostream>
#include <fstream>
#include <string>

class C_Test
{
private:
	/* список свойств и методов для использования внутри класса */
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
	bool get_status() const /* Константная функция - не может менять атрибуты класса. Только получать их */
	{
		return file.is_open();
	}
	void additional_recording() {
		
	}

	/* список методов доступных другим функциям и объектам программы */
protected:
	/*список средств, доступных при наследовании*/

};
