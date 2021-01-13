#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;

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

void print_and_add(int t, std::queue<int>& q2, std::queue<int>& q3, std::queue<int>& q5) {
    if (t != 1) {
        std::cout << t << ' ';
    }
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
        int x = minnum(q2.front(), q3.front(), q5.front());
        print_and_add(x, q2, q3, q5);
        k++;
        if (x == q2.front())
            q2.pop();
        if (x == q3.front())
            q3.pop();
        if (x == q5.front())
            q5.pop();
    }
    return 0;
}