
#include "Lab5_2.h"
#include<ctime>
//#include <iostream>
using std::cout;
using std::cin;
int main()
{

	matr matrA(3,3);
	double arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	int choice = 0;
	while (true) {
		cout << "Select task:\n" << "1. input_matr_std\n"
			<< "2. input_matr_int\n"
			<< "3. input_matr_arr\n"
			<< "4. sum_std\n"
			<< "5. sum_arr\n"
			<< "6. mult_std\n"
			<< "7. mult_arr\n"
			<< "8. Exit\n";
		cin >> choice;
		switch (choice) {
			 
		case 1: {
			cout << "Matrix A\n";
			matrA.input();
			break;
		}
		case 2: {
			int i = 0, j = 0;
			cout << "Input number of rows: ";
			cin >> i;
			cout << "Input number of columns: ";
			cin >> j;
			
			
			break;
		}
		case 3: {
			bool flag;
			matr matrB;
			cout << "Matrix B\n";
			matrB.input();
			matrB.print();
			flag = matrA.sum(&matrB);
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
			cout << "A=A*B:\n";
			matrA.mult(&matrB);
			matrA.print();
			cout << std::endl;
			break;
		}
		case 5: {
			double x = 0;
			cout << "Enter a multiplier: ";
			cin >> x;
			
			matrA.print();
			cout << std::endl;
			break;
		}
		case 6: {
			cout << "Trace:\n";
			

			break;
		}
		case 7: {
			cout << "Det:\n";
			 
			break;
		}
		case 8: {
			cout << "BB\n";
			//delete[]arr;
			
			return 0;
		}
		default: {
			cout << "Select task again\n";
		}
		}
	}

	return 0;
}

matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}
matr::matr(int i, int j) {
	rows = i;
	cols = j;
	elems = new double[rows * cols];
}
matr::matr(int i, int j, const double* arr) {
	rows = i;
	cols = j;
	elems = new double[sizeof(arr) / sizeof(arr[0])];
}
matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}

void matr::input()
{
	cout << "Input number of rows:";
	cin >> rows;
	cout << "Input number of columns:";
	cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * cols];
	srand(time(0));
	for (int i = 0; i < rows * cols; i++)
		//cin >> elems[i];
		elems[i] = rand() % 10;

}
void matr::input(int i, int j) {
	srand(time(0));
	for (int k = 0; k < i * j; k++)
		elems[i] = rand() % 10;
}
void matr::input(int i, int j, const double* arr) {
	for (int k = 0; k < i * j; k++) {
		elems[i] = arr[i];
	}
}
void matr::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << get_elem(i, j) << "\t";
		cout << std::endl;
	}
	cout << std::endl;
}

double matr::get_elem(int i, int j)
{
	return elems[i * cols + j];
}
int matr::get_columns() {
	return cols;
}
int matr::get_rows() {
	return rows;
}
bool matr::sum(const matr* matr2)
{
	if (rows != matr2->rows || cols != matr2->cols)
		return false;
	for (int i = 0; i < rows * cols; i++)
		elems[i] = elems[i] + matr2->elems[i];
	return true;
}
bool matr::sum(const double* arr2) {
	if (sizeof(elems) / sizeof(elems[0]) != sizeof(arr2) / sizeof(arr2[0]))
		return false;
	for (int k = 0; k < rows * cols; k++) {
		elems[k] += arr2[k];
	}
}


bool matr::mult(const matr* matr2) {
	matr MatrCopy;
	MatrCopy.copy(this);
	if (cols == matr2->rows) {
		if (elems != nullptr) {
			delete[] elems;
			cols = matr2->cols;
			elems = new double[cols * rows]{ 0 };
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				for (int k = 0; k < MatrCopy.cols; k++) {

					this->elems[i * cols + j] = MatrCopy.get_elem(i, k) * matr2->elems[k * cols + j];

				}
			}
		}
		return true;
	}
	else {
		cout << "Error\n";
		return false;
	}
}
bool matr::mult(int i, int j, const double* arr2) {
	matr MatrCopy;
	MatrCopy.copy(this);
	if (cols == i) {
		if (elems != nullptr) {
			delete[] elems;
			cols = j;
			elems = new double[cols * i]{ 0 };
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				for (int k = 0; k < MatrCopy.cols; k++) {

					elems[i * cols + j] = MatrCopy.get_elem(i, k) * arr2[k * cols + j];

				}
			}
		}
		return true;
	}
	else {
		cout << "Error\n";
		return false;
	}
}
void matr::copy(const matr* matr)
{
	cols = matr->cols;
	rows = matr->rows;
	elems = new double[cols * rows];
	for (int i = 0; i < cols * rows; i++)
		elems[i] = matr->elems[i];
}

