#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;
//функция нахождения минимума из трех чисел
int minnum(int a, int b, int c) {
    int min;
    if (a < b) {
        min = a;
    }
    else {
        min = b;
    }
    if (min > c) {
        min = c;
    }
    return min;
}
//функция которая выводит Т и добавляет в очереди результаты умножения минимума из первых элементов очередей на коэффициенты
void output_in(int t, std::queue<int>& q2, std::queue<int>& q3, std::queue<int>& q5) {
    cout << t << ' ';
    q2.push(t * 2);
    q3.push(t * 3);
    q5.push(t * 5);
}

int main()
{
    cout << "Input number:\n";
    int n;
    cin >> n;

    queue<int> q2;
    queue<int> q3;
    queue<int> q5;

    q2.push(2);
    q3.push(3);
    q5.push(5);
    int k = 0;

    while (k != n) {
        int x = minnum(q2.front(), q3.front(), q5.front());//находим минимум из первых элементов очередей
        output_in(x, q2, q3, q5);//выводим икс и добавляем элементы в конец очередей см выше
        k++;//увеличиваем счетчик вывода
        if (x == q2.front())
            q2.pop(); //удаляем первый элемент очереди если он совпал с минимумом 
        if (x == q3.front())
            q3.pop();
        if (x == q5.front())
            q5.pop();
    }
    return 0;
}