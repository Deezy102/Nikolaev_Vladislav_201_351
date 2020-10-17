#include <iostream>;

using std::cout;
using std::cin;
using std::endl;

void print(int* arr, int  n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void BoubleSort(int* arr, int n) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void CountSort(char* arr, int* pods, int n) {
	for (int i = 0; i < n; i++) {
		pods[int(arr[i] - 'a')] = pods[int(arr[i] - 'a')] + 1;
	}
	int i = 0;
	for (int j = 0; j < 26; j++) {
		while (pods[j] != 0) {
			arr[i] = char(j + int('a'));
			pods[j]--;
			i++;
		}
	}
	
}

void Merge(int *arr, int begin, int end)
{
	int i = begin;// i и j это временные границы, t - счетчик массива d, масссив d - хранилище эл-тов после слияния
	int sred = begin + (end - begin) / 2;
	int j = sred + 1;
	int t = 0;
	int d[1000];

	while (i <= sred && j <= end) {
		if (arr[i] <= arr[j]) {//если элемент из левой половины меньше эл-та из правой то записываем в массив д и двигаем левую границу
			d[t] = arr[i];
			i++;
		}
		else {//иначе забираем правый эл-т и сдвигаем правую гранницу
			d[t] = arr[j];
			j++;
		}
		t++;//выбираем следующую ячейку вспомогательного массива
	}
	//если первое условие в цикле не выполняется то мы выполняем один из двух следующих циклов т.е. переписываем либо левую либо правую часть
	//таким образом мы делаем проверку заполнили ли мы до конца правую или левую часть
	while (i <= sred) {
		d[t] = arr[i]; i++; t++;
	}
	while (j <= end) {
		d[t] = arr[j]; j++; t++;
	}
	//звполняем результирующий массив значениями из вспомогательного массив 
	for (i = 0; i < t; i++)
		arr[begin + i] = d[i];
}

void MergeSort(int* arr, int left, int right)
{
	int  t;
	if (left < right)//если левая граница больше либо равна правой то сортировать нечего
		if (right - left == 1) {//проверка на то что массив состоит из двух элементов
			if (arr[right] < arr[left]) {
				t = arr[left];
				arr[left] = arr[right];
				arr[right] = t;
			}
		}
		else {
			MergeSort(arr, left, left + (right - left) / 2);//сначала левую часть делим пополам, пополам, пополам...
			MergeSort(arr, left + (right - left) / 2 + 1, right);//потом правую часть делим пополам, пополам, пополам...
			Merge(arr, left, right);
		}
}

int main() {

	setlocale(LC_ALL, "Russian");
	int choice = 0;

	while (true) {
		cout << "Выберите действие:\n" << "1. Сортировка \"пузырьком\" числового массива\n" << "2. Сортировка подсчетом символьного массива\n";
		cout << "3. Сортировка слиянием числового массива\n" << "4. Выход\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			int n;
			cout << "Введите размер массива: ";
			cin >> n;
			int arr[1000] = { 0 };
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}

			BoubleSort(arr, n);
			print(arr, n);
			break;
		}
		case 2: {
			int n = 0;
			char arr[1000] = { 0 };
			int pods[26] = { 0 };

			cout << "Введите размер массива: ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			CountSort(arr, pods, n);
			

			for (int i = 0; i < n; i++) {
				cout << arr[i] << "  ";
			}
			cout << endl;
			break;
		}
		case 3: {
			int n = 0;
			int arr[1000] = { 0 };
			int d[1000] = { 0 };
			cout << "Введите размер массива: ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			MergeSort(arr, 0, n - 1);
			print(arr, n);
			break;
		}
		case 4: {
			cout << "До свидания";
			return 0;
		}
		default: {
			cout << "Выберите действие еще раз\n";
		}
		}
	}

	return 0;
}