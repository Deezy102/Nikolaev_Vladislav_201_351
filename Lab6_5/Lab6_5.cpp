#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <utility>

using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::list;
using std::ifstream;
//функция сравнения номеров групп для функции сорт 
bool Comparing(pair<int, string> left, pair<int, string> right) {
	if (left.first < right.first) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int group;
	string surname;
	list<pair<int, string>> studlist;//объявление листа с парами <группа, фамилия>
	//итератор для обращения к элементам списка
	list<pair<int, string>>::iterator iter;

	ifstream studfile("students_list.txt", std::ios::in);//подготовка файла для ввода из файла
	if (!studfile.is_open()) {//проверка на открытие
		cout << "try again\n";
	}
	else {
		while (!studfile.eof()) {//пока не пустой считывает значения и заносит пары в список
			int group = 0;
			string surname;
			studfile >> group >> surname;
			studlist.push_back(make_pair(group, surname));
			
		}
		
	}
	//сортировка листа с парами через функцию сравнения тк не уверен что пары сортируются просто так
	studlist.sort(Comparing);
	for (iter = studlist.begin(); iter != studlist.end(); iter++) {
		cout << iter->first << "  "<<iter->second << std::endl;
	}
	return 0;
}
