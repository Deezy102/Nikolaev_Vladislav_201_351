#pragma once
#include <string>
#include <iostream>
using std::string;
class Human
{
protected:
	string surname;
	string name;
	int age;
public:
	Human();//конструктор по умолчанию
	Human(string a, string b, int c);//конструктор через фамилию имя и возраст
	~Human();//деструктор класса
	string get_surname();//функция получения фамилии
	string get_name();//функция получения имени
	int get_age();//функция получения возраста
	//перегрузка оператора вывода для данного класса
	friend std::ostream& operator<< (std::ostream& out, const Human& src);

};
