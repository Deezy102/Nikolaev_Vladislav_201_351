#include<iostream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

void input_mas(int*& arr, int* size, int*& sum_arr) {
	if (arr != nullptr) {
		delete[] arr; //очищение памяти 
	}
	cout << "Введите длину массива: ";
	cin >> *size;
	arr = new int[*size];//массив длины сайз задается при помощи функции рандома
	srand(time(0));
	for (int i = 0; i < *size; i++) {
		arr[i] = 100 + rand() % 9900;
	}

}
void print_mas(const int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void SumChetPos(const int* arr, const int size, int* sum_arr) {
	for (int i = 0; i < size; i++) {
		int sum = 0;
		int x = arr[i];
		while (x > 0) {
			x /= 10;//убираем нечетный разряд
			sum += x % 10;//увеличиваем сумму на цифру в четном разряде 
			x /= 10;//убираем считанный разряд
		}
		sum_arr[i] = sum;//записываем в соответсвующую ячейку массива для сумм сумму числа 
	}
}
void SortChetPos(int* arr, const int size, int* sum_arr) {
	int t = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (sum_arr[j] > sum_arr[j + 1]) {//сортируем пузырьком массив с суммами и если там элементы меняются местами 
				t = sum_arr[j];
				sum_arr[j] = sum_arr[j + 1];
				sum_arr[j + 1] = t;
				//то меняем и соответствующие элементы и в исходном массиве
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
void Sort(int* arr, const int size) {
	int t = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if ((arr[j] % 10) != (arr[j + 1] % 10)) {//условие задания добавлено в сортировку пузырьком
				if (arr[j] % 10 > arr[j + 1] % 10) {
					t = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = t;
				}
			}
			else if (arr[j] < arr[j + 1]) {
				t = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
		}
	}
}


int main() {

	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int size = 0;
	int* sum_arr = nullptr;
	int* arr = nullptr;
	while (true) {
		cout << "Выберите действие:\n" << "1. Ввод массива  "
			<< "2. Вывод массива в консоль  "
			<< "3. Сортировка по сумме цифр, стоящих на четных местах  "
			<< "4. Сортировка по последней цифре  "
			<< "5. Выход\n";
		cin >> choice;
		switch (choice) {
		case 1: {

			input_mas(arr, &size, sum_arr);

			break;
		}
		case 2: {
			print_mas(arr, size);
			break;
		}
		case 3: {
			sum_arr = new int[size];
			SumChetPos(arr, size, sum_arr);
			SortChetPos(arr, size, sum_arr);
			delete[] sum_arr;
			break;
		}
		case 4: {
			Sort(arr, size);
			break;
		}
		case 5: {
			cout << "До свидания";
			delete[] arr;
			delete[] sum_arr;
			return 0;
		}
		default: {
			cout << "Выберите действие еще раз\n";
		}
		}
	}
	return 0;
}
