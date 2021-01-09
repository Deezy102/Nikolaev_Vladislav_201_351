#include <deque>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "Coords.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::deque;

bool PalindromCheck(const string str) {
	deque<char> deq;
	
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
	int k = deq.size() / 2;
	for (int i = 0; i < k; i++) {
		if (deq.front() != deq.back()) {
			return false;
		}
		else {
			deq.pop_front();
			deq.pop_back();
		}
	}
	return true;
}

deque<Coords> FindStartPosition(deque<Coords> d_crd) {
	
	int min_x = d_crd[0].get_x();
	int start_in = d_crd[0].get_index();
	
	for (int i = 1; i < d_crd.size(); i++) {
		if (d_crd[i].get_x() < min_x) {
			min_x = d_crd[i].get_x();
			start_in = d_crd[i].get_index();
		}
	}
	Coords buffer(d_crd[0]);
	d_crd[0] = d_crd[start_in];
	d_crd[start_in] = buffer;
	
	return d_crd;
}
void SortByAngle(deque<Coords> d_crd) {
	d_crd[0].set_angle(0);
	for (int i = 1; i < d_crd.size(); i++) {
		double vector_x = d_crd[i].get_x() - d_crd[0].get_x();
		double vector_y = d_crd[i].get_y() - d_crd[0].get_y();
		double angle = acos(vector_x / sqrt((vector_x * vector_x) + (vector_y * vector_y)));
		d_crd[i].set_angle(angle);
		cout << d_crd[i].get_angle() << "  ";
	}
	cout << endl;
	cout << d_crd.size() << endl;
	for (int i = 0; i < d_crd.size()-1; i++) {
		for (int j = 1; j < d_crd.size() - i - 1; j++) {
			if (d_crd[j].get_angle() > d_crd[j + 1].get_angle()) {
				Coords Buf = d_crd[j];
				d_crd[j] = d_crd[j + 1];
				d_crd[j + 1] = Buf;
			}
		}
	}
	for (int i = 0; i < d_crd.size(); i++) {
		cout << d_crd[i].get_angle() << endl;
	}
}
deque<int> FindShell(deque<Coords> d_crd) {
	deque<int> shell;
	deque<int> buf_index;
	int p = 0;
	int x = 2;
	shell.push_back(d_crd[0].get_index());
	for (int i = 1; i < d_crd.size(); i++) {
		buf_index.push_back(d_crd[i].get_index());
	}
	
	for (auto i = buf_index.begin(); i != buf_index.end(); i++) {
		int vect_mult = (d_crd[i].get_x() - d_crd[p].get_x()) * (d_crd[x].get_y() - d_crd[p].get_y())
			- (d_crd[i].get_y() - d_crd[p].get_y()) * (d_crd[x].get_x() - d_crd[p].get_x());

		if (vect_mult >= 0) {
			shell.push_back(d_crd[i].get_index());
		}
		else {
			d_crd.erase(i);
			i--;
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
					d_crd.push_back(Coords(x, y, i));
				}
				d_crd = FindStartPosition(d_crd);
				SortByAngle(d_crd);
				deque<int>shell = FindShell(d_crd);
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