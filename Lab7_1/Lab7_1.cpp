#include <iostream>
#include <vector>
#include "Human.h"

using std::vector;
using std::cin;
using std::cout;

//функция сравнения фамилий 
bool SurnameCompare(Human left, Human right) {
	if (left.get_surname() < right.get_surname()) {
		return true;
	}
	else {
		return false;
	}
}
//функция сравнения имен
bool NameCompare(Human left, Human right) {
	if (left.get_name() < right.get_name()) {
		return true;
	}
	else {
		return false;
	}
}
//функция сравнения возраста
bool AgeCompare(Human left, Human right) {
	if (left.get_age() < right.get_age()) {
		return true;
	}
	else {
		return false;
	}
}
//функция-шаблон сравнения для встроенных типов
template <typename Temp>
bool Compare(Temp left, Temp right) {
	if (left < right) {
		return true;
	}
	else {
		return false;
	}
}
//функция быстрой сортировки с заменой сравнения элементов на функцию сравнения
//которая передается в качестве аргумента как указатель а в самой функции разыменовывается 
template <typename Temp>
void QuickSort(vector<Temp>& data, int left, int right, bool (*Compare)(Temp, Temp))
{
	
	int i = left;
	int j = right;
	Temp pivot = data[(i + j) / 2];
	Temp t;

	while (i <= j)
	{
		while (Compare(data[i], pivot))//compare == data[i] < pivot
			i++;
		while (Compare(pivot, data[j])) // такой же принцип pivot < data[j]
			j--;
		if (i <= j)
		{
			t = data[i];
			data[i] = data[j];
			data[j] = t;
			i++;//сдвиг границ
			j--;
		}
	}
	if (j > left)
		QuickSort(data, left, j, Compare);//рекурсия для сортировки элементов до пивота
	if (i < right)
		QuickSort(data, i, right, Compare); //рекурсия для сортировки после пивота
}

int main()
{
	//создание и инициализация векторов
	vector<double> dataDbl{ 1.4, 2.3, 10.001, 0.5, -90.7, -4.2 };
	vector<string> dataStr{ "giraffe" , "fish", "whale", "orange", "apple" };
	vector<Human> dataHum{ {"Ryabov", "Kostya", 18}, {"Ogirok", "Sonya", 20}, {"Nikolaev", "Vlad", 19}, {"Kondrashov", "Egor", 24}};
	//вызов функции сортировки и вывод вектора с элементами типа дабл
	QuickSort(dataDbl, 0, dataDbl.size() - 1, Compare);
	for (int i = 0; i < dataDbl.size(); i++) {
		cout << dataDbl[i] << "  ";
	}
	cout << std::endl;
	//вызов функции сортировки и вывод вектора с элементами типа стринг
	QuickSort(dataStr, 0, dataStr.size() - 1, Compare);
	for (int i = 0; i < dataStr.size(); i++) {
		cout << dataStr[i] << "  ";
	}
	cout << std::endl;
	//вызов функции сортировки по фамилии и вывод вектора с элементами класса Human 
	QuickSort(dataHum, 0, dataHum.size() - 1, SurnameCompare);
	for (int i = 0; i < dataHum.size(); i++) {
		cout << dataHum[i];
	}
	cout << "_________\n";
	//вызов функции сортировки по имени и вывод вектора с элементами класса Human 
	QuickSort(dataHum, 0, dataHum.size() - 1, NameCompare);
	for (int i = 0; i < dataHum.size(); i++) {
		cout << dataHum[i];
	}
	cout << "_________\n";
	//вызов функции сортировки по возрасту и вывод вектора с элементами класса Human 
	QuickSort(dataHum, 0, dataHum.size() - 1, AgeCompare);
	for (int i = 0; i < dataHum.size(); i++) {
		cout << dataHum[i];
	}


	
	return 0;
}
