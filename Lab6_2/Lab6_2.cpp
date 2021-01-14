#include <deque>
#include <string>
#include <iostream>
#include "Coords.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::deque;
//индетификатор и последовательность
#define PI 3.14159;
//функция проверки на палиндром
bool PalindromCheck(const string str) {
	
	deque<char> deq;
	//заносим в дек посимвольно строку без пробелов и в малом регистре
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			if (str[i] >= 'A' and str[i] <= 'Z') {
				deq.push_back(char(int(str[i]) + 32));
			}
			else {
				deq.push_back(str[i]);
			}
		}
	}
	//находим +-серидину
	int k = deq.size() / 2;
	//проверка первого и последнего элемента дека если совпадают чистим если нет возвращаем фолз
	for (int i = 0; i < k; i++) {
		if (deq.front() != deq.back()) {
			return false;
		}
		else {
			if (deq.size() != 1) {
				deq.pop_front();
				deq.pop_back();
			}
			else {
				return true;
			}
		}
	}
	return true;
}

//функция возвращающая стартовый элемент класса Коорд
Coords FindStartPosition(deque<Coords> d_crd) {

	int min_x = d_crd[0].get_x();
	int min_y = d_crd[0].get_y();
	int start_in = 0;
	//ищем самую низкую из левых 
	for (int i = 1; i < d_crd.size(); i++) {
		if ((d_crd[i].get_x() < min_x) || ((d_crd[i].get_x() == min_x) && (d_crd[i].get_y() < min_y))) {
			min_x = d_crd[i].get_x();
			min_y = d_crd[i].get_y();
			start_in = i;
		}
	}

	Coords start(d_crd[start_in]);
	return start;
}
//сортировка по углу между вектором (старт, проверяемая точка) и осью Х
void SortByAngle(deque<Coords>& d_crd, Coords start) {
	//сетаем углы в элементы дэка
	for (int i = 0; i < d_crd.size(); i++) {
		double vector_x = d_crd[i].get_x() - start.get_x();
		double vector_y = d_crd[i].get_y() - start.get_y();
		double angle = acos(vector_x / sqrt((vector_x * vector_x) + (vector_y * vector_y))) * 180 / PI;
		d_crd[i].set_angle(angle);

	}
	cout << endl;
	//сортруем по углу элементы дэка
	for (int i = 0; i < d_crd.size() - 1; i++) {
		for (int j = 0; j < d_crd.size() - i - 1; j++) {
			if (d_crd[j].get_angle() > d_crd[j + 1].get_angle()) {
				Coords Buf = d_crd[j];
				d_crd[j] = d_crd[j + 1];
				d_crd[j + 1] = Buf;
			}
		}
	}
}
//функция которая проверяет в какую сторону совершен поворот если влево то тру если вправо то фолз 
bool vect_mult(Coords prelast, Coords last, Coords now) {
	int vect_mult = (last.get_x() - prelast.get_x()) * (now.get_y() - prelast.get_y())
		- (last.get_y() - prelast.get_y()) * (now.get_x() - last.get_x());
	if (vect_mult >= 0) {
		return true;
	}
	else {
		return false;
	}
}
//функция которая ищет ВО
deque<Coords> FindShell(deque<Coords>& d_crd) {

	deque<Coords> shell;//результирующий дэк
	Coords start = FindStartPosition(d_crd);//стартовая позиция
	shell.push_back(start);//заносим стартовую позицию в результирующий дэк
	d_crd.erase(std::find(d_crd.begin(), d_crd.end(), start));//удаляем стартовую позицию из стандартного дэка

	SortByAngle(d_crd, start);//сортировка по степени левизны

	shell.push_back(d_crd[0]);//добавляем точку для создания первого вектора оболочки 
	d_crd.erase(d_crd.begin());//удаляем ее из стандартного дэка

	for (int i = 0; i < d_crd.size(); i++) {
		//если левый поворот то добавляем точку в результирующий дэк
		if (vect_mult(*(shell.end() - 2), shell.back(), d_crd[i]) == true) {
			shell.push_back(d_crd[i]);
		}
		else {//если был совершен правый поворот то удаляем из результирующего дэка неверные точки пока поворот не станет левым 
			while (!(vect_mult(*(shell.end() - 2), shell.back(), d_crd[i]) == true)) {
				shell.pop_back();
			}
			shell.push_back(d_crd[i]);
		}
	}
	return shell;
}
int main() {
	int choice = 0;
	while (true) {
		cout << "1. Palindrome\n"
			<< "2. Shell search\n"
			<< "3. Exit\n";
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1: {
				
				bool flag;
				string str;
				cout << "Input string: \n";
				getline(cin, str);
				//Tenet ne n Tenet
				flag = PalindromCheck(str);
				if (flag == true) {
					cout << "True\n";
				}
				else {
					cout << "False\n";
				}
				break;
			}
			case 2: {
				int n, x, y;
				deque<Coords> d_crd;
				cout << "Number of points: ";
				cin >> n;
				for (int i = 0; i < n; i++) {
					cin >> x >> y;
					d_crd.push_back(Coords(x, y));
				}
				deque<Coords>shell = FindShell(d_crd);
				for (int i = 0; i < shell.size(); i++) {
					cout << shell[i].get_x() << " " << shell[i].get_y() << endl;
				}
				break;
			}
			case 3: {
				cout << "BB";
				return 0;
				
			}
			default: {
				cout << "try again\n";
			}

		}
	}
	return 0;
}