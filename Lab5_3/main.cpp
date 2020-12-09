#include "matr.h"
#include<ctime>
#include <iostream>
using std::cout;
using std::cin;
int main()
{

	
	int choice = 0;
	matr matrA;
	matr matrB;
	cin >> matrA >> matrB;
	cout << "matrA =\n" << matrA;
	cout << matrA + matrB;
	cout << matrA * matrB;
	//while (true) {
	//	cout << "Select task:\n" << "1. input_matr\n"
	//		<< "2. print_matr\n"
	//		<< "3. sum_matr\n"
	//		<< "4. subtraction_matr\n"
	//		<< "5. unary_minus\n"
	//		<< "6. trace\n"
	//		<< "7. Det\n"
	//		<< "8. multiplication\n"
	//		<< "9. Exit\n";
	//	cin >> choice;
	//	switch (choice) {
	//	case 1: {
	//		cout << "Matrix A\n";
	//		cin >> matrA;
	//		//matrA.input();
	//		break;
	//	}
	//	case 2: {
	//		//matrA.print();
	//		cout << matrA;
	//		break;
	//	}
	//	case 3: {
	//		matr matrB;
	//		cout << "Matrix B\n";
	//		cin >> matrB;
	//		cout << "A+B=\n";
	//		cout << matrA + matrB;
	//		break;
	//	}
	//	case 4: {
	//		matr matrB;
	//		cout << "Matrix B\n";
	//		cin >> matrB;
	//		cout << "A-B=\n";
	//		cout << matrA - matrB;
	//		break;
	//	}
	//	case 5: {
	//		cout << -matrA;
	//		break;
	//	}
	//	case 6: {
	//		cout << "Trace:\n";
	//		cout << matrA.trace() << std::endl;

	//		break;
	//	}
	//	case 7: {
	//		cout << "Det:\n";
	//		cout << matrA.det() << std::endl;
	//		break;
	//	}
	//	case 8: {
	//		matr matrB;
	//		cout << "Matrix B\n";
	//		cin >> matrB;
	//		cout << "A*B=\n";
	//		matr matrC(3, 3);
	//		cout << matrA * matrB;
	//		
	//		break;
	//	}
	//	case 9: {
	//		cout << "BB\n";

	//		return 0;
	//	}
	//	default: {
	//		cout << "Select task again\n";
	//	}
	//	}
	//}

	return 0;
}

