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
	Human();
	Human(string a, string b, int c);
	~Human();
	string get_surname();
	string get_name();
	int get_age();

	friend std::ostream& operator<< (std::ostream& out, const Human& src);

};
