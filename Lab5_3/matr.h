#pragma once
#include "matr.h"
#include <iostream>

class matr
{
private:
	
	int rows;//number of rows
	double* elems; // elements
public:
	matr();
	matr(const matr& matr);
	~matr();
	
	double get_elem(int i, int j);
	int get_columns();
	int get_rows();
	void set_element(int row, int column, double sum);

	double trace();
	double det();
	friend std::istream& operator>> (std::istream& in, matr& matrA);
	friend std::ostream& operator<< (std::ostream& out, const matr& matrA);
	friend matr operator+(const matr& matrA, const matr& matrB);
	friend matr& operator-(matr& matrA, const matr& matrB);
	matr operator-();
	friend matr operator*(const matr& matrA, const matr& matrB);
};
