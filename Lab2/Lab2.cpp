#include <iostream>
//#include <string>
using std::cin;
using std::cout;
using std::endl;

unsigned long long bincoef(int n, int k)
{

    if (k > n / 2) {
        k = n - k;// тк в выводе получается симметрия то функция в точке (n,k) = функции в точке (n, n-k)
//пример: n=10 k=4 и n=10 k=6 функция имеет вид 10!/(4!*6!) от перестановки мест множителей в знаменателе результат не поменяется->экономится память    
    }
    if (k == 1) {
        return n; // при сокращении дроби в числителе остается один множитель равный n, а в знаменателе 1! -> return n
    }
    if (k == 0) {
        return 1; // при к=0 функция примет вид 1/0! = 1
    }
    unsigned long long r = 1;
    for (int i = 1; i <= k; i++) {
        r = r * (n - k + i);
        r = r / double(i);
        //идет подсчет числителя и одновременное деление на соответствующий множитель знаменателя
    }
    return r;
}

void task1() {
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= i + 1; j++) {
            cout << j;
        }
        cout << endl;
    }
}

void task2() {
    int n;
    int k;
    cin >> n;
    cout << endl;
    for (int i = 0; i <= n; i++) {
        k = i;
        cout << bincoef(n, k) << endl;
    }
}

void task3() {
    cout << "Чтобы закончить введите любой символ\n";

    int x = 0;
    int k = 0;
    long int sum = 0;
    //способ остановки через пустую строку
    /*getchar();// убираем символ \n который появляется после выбора действия
    std::string str;
   while (true) {
        getline(cin, str);
        if (str.empty()) { //проверяем пустая ли строка если да то выходим из цикла
            break;
        }
        sum += std::stoi(str);//переводим строку в число
        k++;
    }*/
    //способ остановки через любой символ
    while (true) {
        cin >> x;
        if (!cin) { //если ввели не число то убирается флаг ошибки и этот символ извлекается из потока и происходит выход из цикла
            cin.clear();
            cin.get();
            break;
        }
        sum += x;
        k++;
    }
    cout << "Среднее арифметическое:" << double(sum) / k << endl << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    while (true)
    {
        cout << "Что вы хотите выполнить?\n" << "1. Числовой треугольник\n" << "2. Биноминальные коэффициенты\n" << "3. Среднее арифметическое \n"
            << "4. Выход\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            task1();
            break;
        }
        case 2: {
            task2();
            cout << endl;
            break;
        }
        case 3: {
            task3();
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
