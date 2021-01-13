#include <iostream>
#include <vector>
#include "Human.h"

using std::vector;
using std::cin;
using std::cout;


bool SurnameCompare(Human left, Human right) {
	if (left.get_surname() < right.get_surname()) {
		return true;
	}
	else {
		return false;
	}
}
bool NameCompare(Human left, Human right) {
	if (left.get_name() < right.get_name()) {
		return true;
	}
	else {
		return false;
	}
}
bool AgeCompare(Human left, Human right) {
	if (left.get_age() < right.get_age()) {
		return true;
	}
	else {
		return false;
	}
}
template <typename Temp>
bool Compare(Temp left, Temp right) {
	if (left < right) {
		return true;
	}
	else {
		return false;
	}
}
template <typename Temp>

void QuickSort(vector<Temp>& data, int left, int right, bool (*Compare)(Temp, Temp))
{
	
	int i = left;
	int j = right;
	Temp pivot = data[(i + j) / 2];
	Temp t;

	while (i <= j)
	{
		while (Compare(data[i], pivot))//compare data[i] < pivot
			i++;
		while (Compare(pivot, data[j])) // pivot < data[j]
			j--;
		if (i <= j)
		{
			t = data[i];
			data[i] = data[j];
			data[j] = t;
			i++;
			j--;
		}
	}
	if (j > left)
		quickSort(data, left, j, Compare); //
	if (i < right)
		quickSort(data, i, right, Compare);
}

int main()
{
	int arr[3] = { 3, 2, 1 };

	vector<double> dataDbl{ 1.4, 2.3, 10.001, 0.5, -90.7, -4.2 };
	vector<string> dataStr{ "giraffe" , "fish", "whale", "orange", "apple" };
	vector<Human> dataHum{ {"Ryabov", "Kostya", 18}, {"Ogirok", "Sonya", 20}, {"Nikolaev", "Vlad", 19}, {"Kondrashov", "Egor", 18}};

	QuickSort(dataDbl, 0, dataDbl.size() - 1, Compare);
	for (int i = 0; i < dataDbl.size(); i++) {
		cout << dataDbl[i] << "  ";
	}
	cout << std::endl;
	QuickSort(dataStr, 0, dataStr.size() - 1, Compare);
	for (int i = 0; i < dataStr.size(); i++) {
		cout << dataStr[i] << "  ";
	}
	cout << std::endl;
	//int choice = 0;
	QuickSort(dataHum, 0, dataHum.size() - 1, SurnameCompare);
	for (int i = 0; i < dataHum.size(); i++) {
		cout << dataHum[i];
	}
	cout << "_________\n";

	QuickSort(dataHum, 0, dataHum.size() - 1, NameCompare);
	for (int i = 0; i < dataHum.size(); i++) {
		cout << dataHum[i];
	}
	cout << "_________\n";
	QuickSort(dataHum, 0, dataHum.size() - 1, AgeCompare);
	for (int i = 0; i < dataHum.size(); i++) {
		cout << dataHum[i];
	}


	
	return 0;
}
