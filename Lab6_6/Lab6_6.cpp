#include <map>
#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::ifstream;

int main() {
	//итератор для обращения к элементам мапа
	map<string, int>::iterator iter;
	map<string, int> text_map;//объявление мапа
	int total = 0;//счетчик слов
	ifstream textfile("text_example.txt", std::ios::in);//подготовка файла для ввода из файла
	if (!textfile.is_open()) {//проверка на открытие 
		cout << "try again\n";
	}
	else {
		while (!textfile.eof()) {//пока файл не пустой

			string simple;
			textfile >> simple; //таким образом можно считывать по одному слову 
			//проверки на знаки препинания в начале и конце слова, перевод слов в малый регистр, проверки на пустые строки
			if ((!((simple[0] <= 'Z' && simple[0] >= 'А')||(simple[0] <= 'z' && simple[0] >= 'a')))||((simple[0]=='"')||(simple[0] == '('))) {
				simple.erase(0);
			}
			if (simple.empty()) {
				continue;
			}
			if (!(simple[0] <= 'z' && simple[0] >= 'a')) {
				simple[0] = char(int(simple[0]) + 32);
			}
			if (!(simple[simple.length()-1] <= 'z' && simple[simple.length()-1] >= 'a')) {
				simple.erase(simple.length()-1);
			}
			if (simple.empty()){
				continue;
			}
			//если такой ключ есть то значение увеличиваем на один
			if (text_map.count(simple) != 0) {
				text_map[simple]++;
			}
			else {//или же создаем новый
				text_map.insert({ simple, 1 });
			}

			total++;//увеличение счетчика слов

		}
	}
	cout << "Total words is " << total << std::endl;
	//вывод слов и процентного соотношения
	for (iter = text_map.begin(); iter != text_map.end(); iter++) {
		cout << (*iter).first <<  "___" << iter->second / (total / 100.) << '%' << std::endl;
	}
	return 0;
}