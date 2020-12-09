#pragma once
#include "Lab5_2.h"
#include<iostream>

class matr
{
private:
	int cols;// number of columns
	int rows;//number of rows
	double* elems; // elements
public:
	matr();
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	~matr();

	void input();
	void input(int rows, int cols);
	void input(int rows, int cols, const double* arr);
	void print();
	double get_elem(int i, int j);
	int get_columns();
	int get_rows();

	bool sum(const matr* matr2);
	bool sum(const double* arr);
	void copy(const matr* matr);
	bool mult(const matr* matr2);
	bool mult(int i, int j, const double* arr2);
	
};