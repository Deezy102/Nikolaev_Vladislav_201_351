#include <iostream>
#include <cstring>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;

void string_input(char* str, const int n) {
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
}

void string_output(char* str, const int n) {
	for (int i = 0; i < n; i++) {
		cout << str[i];
	}
	cout << endl;
}

void palindrom(char* str) {
	int n;
	n = strlen(str);
	bool flag = true;

	for (int i = 0; i < n - 1; i++) {//проверка противоположных элементов если они равны то проверка продолжается и сдвигаются края
		if (str[i] == ' ') {
			i++;
		}
		if (str[n - 1] == ' ') {
			n--;
		}
		if ((int(str[i]) == int(str[n - 1])) or (int(str[i]) - 32 == int(str[n - 1]))
			or (int(str[i]) == int(str[n - 1] - 32))) {
			n--;
			continue;
		}
		else {//если не равны то флаг меняется на false и проверка заканчивается
			flag = false;
			break;
		}
	}
	if (flag == true) {
		cout << "Является палиндромом\n";
	}
	else {
		cout << "Не является палиндромом\n";
	}
	
}
int find(char* str, const char* sub_str, const int pos) {
	int ptr = 0;
	int start = 0;
	int match = 0;
	for (int i = pos; i < strlen(str); i++) {
		if (sub_str[match] == str[i]) {
			if (match == 0) {
				start = i;
			}
			match++;
			if (match == strlen(sub_str)) {
				ptr = start;
				break;
			}
		}
		else {
			match = 0;
			i--;
			continue;
		}
		if (ptr != 0) { break; }
	}
	return ptr;
}
int* find2(char* str, char* sub_str) {
	cout << strlen(sub_str) << "<<<<" << endl;
	int* index = nullptr;
	
	index = new int[strlen(str)];//массив для индексов вхождений
	for (int i = 0; i < strlen(str); i++) {
		index[i] = 0;//обнуление массива
	}
	int start = 0;//хранит индекс начала вхождения после передает в массив
	int k = 0;//счетчик позволяет выбрать следующую по порядку ячейку в массиве с индексами
	int match = 0;//счетчик количества совпадений символов строки с подстрокой
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == sub_str[match]) {
			start = i;
			match++;
			while (str[i+1] == sub_str[match]) {
				match++;
				i++; //проверка с подстрокой
			}
			if (match == strlen(sub_str)) {//если кол-во совпалений = длина подстроки
				match = 0;//обнуление счетчика соответсвий 
				index[k] = start;//запоминание индекса вхождения
				k++;//выбор другой ячейки 
				start = 0;//обнуление хранилище индекса вхождения
				i--;//для того чтобы проверить последний символ который может быть началом нового вхождения
			}
			else {
				match = 0;
			}
		}
		
	}
	return index;
}
void Cesar(char* str) {
	int t = 0;//хранит номер символа в таблице аски с учетом сдвига
	int sdvig = 0;
	cout << "Размер сдвига: ";
	cin >> sdvig;
	for (int i = 0; i < strlen(str); i++) {
		if ((int(str[i])<= 64) or (int(str[i]) >= 91 and int(str[i]) <= 96)){//если пробел или какой-то иной символ 
			continue;//то пропуск следующих действий до новой итерации
		}
		t = int(str[i]) + sdvig;
		if (((t > 90) && (int(str[i]) <= 90)) || ((t > 122) && (int(str[i]) <= 122))) {
			t -= 26; //коррекция сдвига в английском алфавите
		}
		/*if (((t >= 0) && (int(str[i]) <= -1)) || ((t >= -32) && (int(str[i]) < -32))) {
			t -= 32;//коррекция сдвига в русском алфавите
		}*/
		str[i] = char(t);//ячейка массива присваивает новое значение
	}
}
void find_name(char* str) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '\"') {
			count++;
		}
		
	}
	
	for (int i = 0; i < strlen(str); i++) {
		if (count % 2 > 0) {
			cout << "Введите строку заново" << endl;
			break;
		}
		if (str[i] == '\"') {
			i++;
			while (str[i] != '\"') {
				cout << str[i];
				i++;
			}
			cout << endl;
		}
	}

}
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 0;
	char* str = new char[255];
	
	while (true) {
		cout << "Выберите действие:\n" << "1. Палиндром  "
			<< "2. Аналог find  "
			<< "3. Шифр Цезаря  "
			<< "4. Поиск названий "
			<< "5. Выход\n";
		cin >> choice;
		cin.get();
		switch (choice) {
		case 1: {
			cout << "Введите строку: \n";
			cin.getline(str,255);
			palindrom(str);
			break;
		}
		case 2: {
			char* sub_str = new char[255];
			cout << "Введите строку: \n";
			cin.getline(str, 255);
			cout << "Введите подстроку для поиска: \n";
			cin.getline(sub_str, 255);
			int pos = 0;
			cout << "Введите стартовую позицию поиска: \n";
			cin >> pos;
			int ptr = find(str, sub_str, pos);
			cout << ptr << endl;
			int* ptr2 = find2(str, sub_str);
			for (int i = 0; i < 255; i++) {
				cout << ptr2[i] << "  ";
				if (ptr2[i + 1] == 0) {
					break;
				}
			}
			cout << endl;
			delete[]ptr2;
			delete[]sub_str;
			break;


		}
		case 3: {
			cout << "Введите строку: \n";
			cin.getline(str, 255);
			Cesar(str);
			cout << str << endl;
			break;
		}
		case 4: {
			cout << "Введите строку: \n";
			cin.getline(str, 255);
			find_name(str);

			break;
		}
		case 5: {
			cout << "До свидания";
			delete[]str;
			return 0;
		}
		default: {
			cout << "Выберите действие еще раз\n";
		}
		}
	}
	return 0;
}