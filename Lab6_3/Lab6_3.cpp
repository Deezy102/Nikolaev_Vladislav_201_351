#include <iostream>
#include <queue>
#include <deque>
using std::deque;
using std::queue;
using std::cout;
using std::cin;

int FindMin(int a, int b, int c) {
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

int main()
{
	queue<int> q2, q3, q5;
	deque<int> dq_all;
	q2.push(2);
	q3.push(3);
	q5.push(5);
	cout << "Input N:";
	int n;
	cin >> n;
	while (q2.size() + q3.size() + q5.size() < n) {
		int min = FindMin(q2.back(), q3.back(), q5.back());
		if (min == q2.back()) {
			q2.push(FindMin(q2.back() * 2, q2.back() * 3, q2.back() * 5));
		}
		if (min == q3.back()) {
			q3.push(FindMin(q3.back() * 2, q3.back() * 3, q3.back() * 5));
		}
		if (min == q5.back()) {
			q5.push(FindMin(q5.back() * 2, q5.back() * 3, q5.back() * 5));
		}
	}
	int length = q2.size();
	for (int i = 0; i < length; i++) {
		dq_all.push_back(q2.front());
		q2.pop();
	}
	length = q3.size();
	for (int i = 0; i < length; i++) {
		dq_all.push_back(q3.front());
		q3.pop();
	}
	length = q5.size();
	for (int i = 0; i < length; i++) {
		dq_all.push_back(q5.front());
		q5.pop();
	}

	for (int i = 0; i < dq_all.size() - 1; i++) {
		for (int j = 0; j < dq_all.size() - i - 1; j++) {
			if (dq_all[j] > dq_all[j + 1]) {
				int temp = dq_all[j];
				dq_all[j] = dq_all[j + 1];
				dq_all[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < dq_all.size(); i++) {
		cout << dq_all[i] << std::endl;
	}
	return 0;
}
