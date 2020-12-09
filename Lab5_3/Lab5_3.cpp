#include "matr.h"
#include<ctime>
#include <iostream>
using std::cin;
using std::cout;
matr::matr()
{
	rows = 0;
	elems = nullptr;
}


matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}
matr::matr(const matr& src)
{
	this->rows = src.rows;
	this->elems = new double[rows * rows]{ 0 };

	for (int i = 0; i < rows * rows; i++)
		elems[i] = src.elems[i];
}

std::istream& operator>> (std::istream& in, matr& matrA) {
	
	cout << "Square matrix!!!\n";
	cout << "Input number of rows:";
	cin >> matrA.rows;
	
	if (matrA.elems != nullptr)
		delete[] matrA.elems;
	matrA.elems = new double[matrA.rows * matrA.rows];
	
	for (int i = 0; i < matrA.rows * matrA.rows; i++) {
		matrA.elems[i] = 0;
	}
	for (int i = 1; i < matrA.rows * matrA.rows;) {
		cin >> matrA.elems[i];
		i += (matrA.rows + 1);
	}
	for (int i = 0; i < matrA.rows * matrA.rows;) {
		cin >> matrA.elems[i];
		i += (matrA.rows + 1);
	}
	for (int i = matrA.rows; i < matrA.rows * matrA.rows;) {
		cin >> matrA.elems[i];
		i += (matrA.rows + 1);
		
	}
	return in;
}
std::ostream& operator<< (std::ostream& out, const matr& matrA) {
	for (int i = 0; i < matrA.rows; i++)
	{
		for (int j = 0; j < matrA.rows; j++)
			out <<matrA.elems[i*matrA.rows+j] << "\t";
		out << std::endl;
	}
	out << std::endl;
	return out;
}


double matr::get_elem(int i, int j)
{
	return elems[i * rows + j];
}
int matr::get_columns() {
	return rows;
}
int matr::get_rows() {
	return rows;
}
matr operator+(const matr& matrA, const matr& matrB) {
	matr MatrCopy(matrA);
	for (int i = 0; i < matrA.rows * matrA.rows; i++)
		MatrCopy.elems[i] = matrA.elems[i] + matrB.elems[i];
	
	return MatrCopy;
}

matr& operator-(matr& matrA, const matr& matrB) {
	for (int i = 0; i < matrA.rows * matrA.rows; i++)
		matrA.elems[i] = matrA.elems[i] - matrB.elems[i];
	return matrA;
}
const matr operator-(const matr& matrA) {
	matr MatrCopy(matrA);
	for (int i = 0; i < MatrCopy.get_rows() * MatrCopy.get_rows(); i++) {
		for (int j = 0; j < MatrCopy.get_rows(); j++) {
			if (MatrCopy.get_elem(i, j) == 0) {
				continue;
			}
			MatrCopy.set_element(i, j, -MatrCopy.get_elem(i, j));
		}
	}
	return matrA;
}
//matr operator*(const matr& matrA, const matr& matrB) {
//	matr MatrCopy(matrA);
//	//MatrCopy.copy(&matrA);
//	/*if (MatrCopy.elems != nullptr) {
//		delete[] MatrCopy.elems;
//		MatrCopy.elems = new double[matrA.cols * matrA.rows]{ 0 };
//	}*/
//	
//	for (int i = 0; i < matrA.rows; i++) {
//		for (int j = 0; j < matrA.rows; j++) {
//			for (int k = 0; k < MatrCopy.rows; k++) {
//
//				MatrCopy.elems[i * MatrCopy.rows + j] += matrA.elems[i * matrA.rows + k] * matrB.elems[k * matrB.rows + j];
//				
//			}
//		}
//	}
//	
//	return MatrCopy;
//	
//}
//void matr::copy(const matr* matr)
//{
//	cols = matr->cols;
//	rows = matr->rows;
//	elems = new double[cols * rows];
//	for (int i = 0; i < cols * rows; i++)
//		elems[i] = matr->elems[i];
//}

//matr operator*(const matr& matrA, const matr& matrB)
//{
//	matr MatrBuf(matrA);
//	cout << MatrBuf;
//	for (int i = 0; i < matrA.rows; i++)
//		for (int j = 0; j < matrA.rows; j++)
//			for (int k = 0; k < MatrBuf.rows; k++)
//				MatrBuf.elems[i * MatrBuf.rows + j] += matrA.elems[i * matrA.rows + k] * matrB.elems[k * matrB.rows + j];
//
//	return MatrBuf;
//}

matr operator*(const matr& matrA, const matr& matrB) {
	matr MatrRes(matrA);
	for (int i = 0; i < matrA.rows; i++) {
		for (int j = 0; j < matrA.rows; j++) {
			double sum = 0;
			for (int k = 0; k < matrA.rows; k++) {
				double a = matrA.elems[i * matrA.rows + k];
				double b = matrB.elems[matrB.rows * k + j];
				sum += a * b;
			}
			MatrRes.set_element(i, j, sum);
		}
	}

	return MatrRes;
}
void matr::set_element(int i, int j, double sum)
{
	elems[i * rows + j] = sum;
}

double matr::trace() {
	double trace = 0;
	if (rows == rows) {
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
	if (rows == rows) {
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