#include "Lab5_1.h"
#include<ctime>
#include <iostream>
using std::cout;
using std::cin;
int main()
{

	int i = 3;
	int j = 3;
	double arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int choice = 0;
	matr matrA;
	//matr matrA(i, j, arr);
	while (true) {
		cout << "Select task:\n" << "1. input_matr\n"
			<< "2. print_matr\n"
			<< "3. sum_matr\n"
			<< "4. mult_matr\n"
			<< "5. mult_by_num\n"
			<< "6. trace\n"
			<< "7. Det\n"
			<< "8. Exit\n";
		cin >> choice;
		switch (choice) {
		case 1: {

			cout << "Matrix A\n";
			matrA.input();
			break;
		}
		case 2: {
			matrA.print();
			break;
		}
		case 3: {
			bool flag;
			matr matrB;
			cout << "Matrix B\n";
			matrB.input();
			matrB.print();
			flag = matrA.sum(&matrB);
			//double arr2[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};
			//flag = matrA.sum(arr2);
			if (flag == false) {
				cout << "Error\n";
			}
			else {
				cout << "A=A+B:\n";
				matrA.print();
			}
			break;
		}
		case 4: {
			matr matrB;
			cout << "Matrix B\n";
			matrB.input();
			matrB.print();
			int i2, j2;
			//cin >> i2;
			//cin >> j2;
			cout << "A=A*B:\n";
			matrA.mult(&matrB);

			//double arr2[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			//matrA.mult(i2, j2, arr2);
			matrA.print();
			cout << std::endl;
			break;
		}
		case 5: {
			double x = 0;
			cout << "Enter a multiplier: ";
			cin >> x;
			matrA.mult_by_num(x);
			matrA.print();
			cout << std::endl;
			break;
		}
		case 6: {
			cout << "Trace:\n";
			cout << matrA.trace() << std::endl;

			break;
		}
		case 7: {
			cout << "Det:\n";
			cout << matrA.det() << std::endl;
			break;
		}
		case 8: {
			cout << "BB\n";

			return 0;
		}
		default: {
			cout << "Select task again\n";
		}
		}
	}

	return 0;
}

