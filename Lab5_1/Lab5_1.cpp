
#include "Lab5_1.h"
#include<ctime>
#include <iostream>
using std::cin;
using std::cout;
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
	elems = new double[i * j];
	for (int k = 0; k < rows * cols; k++) {
		elems[k] = arr[k];
	}
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
void matr::mult_by_num(double num) {
	for (int i = 0; i < rows * cols; i++)
		elems[i] = elems[i] * num;
}
double matr::trace() {
	double trace = 0;
	if (rows == cols) {
		for (int i = 0; i < rows; i++)
			trace += this->get_elem(i, i);
		return trace;
	}
	else {
		cout << "Error code: ";
		return -1;
	}

}
double matr::det() {
	double det = 0;
	if (cols == rows) {
		if (rows == 2) {
			det = elems[0] * elems[3] - elems[1] * elems[2];
		}
		if (rows == 3) {
			det = elems[0] * elems[4] * elems[8] + elems[6] * elems[1] * elems[5] +
				elems[3] * elems[7] * elems[2] - elems[6] * elems[4] * elems[2] - elems[0] * elems[7] * elems[5] -
				elems[3] * elems[1] * elems[8];
		}
		return det;
	}
	else {
		cout << "Under development... Error code: ";
		return -1;
	}
}