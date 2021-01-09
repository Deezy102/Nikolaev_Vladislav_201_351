#include <stack>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;

bool check(const string str, std::stack<char> stack) {
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] == '{') or (str[i] == '[') or (str[i] == '(')) {
			stack.push(str[i]);
		}
		if (str[i] == '}') {
			if (stack.top() == '{') {
				stack.pop();
			}
			else {
				return false;
			}
		}
		if (str[i] == ']') {
			if (stack.top() == '[') {
				stack.pop();
			}
			else {
				return false;
			}
		}
		if (str[i] == ')') {
			if (stack.top() == '(') {
				stack.pop();
			}
			else {
				return false;
			}
		}
	}
	if (stack.empty() == true) {
		return true;
	}
}

int main() {
	std::stack<char> stack;
	bool flag;
	char temp;
	string str;
	cout << "Enter expression: \n";
	cin >> str;
	flag = check(str, stack);
	if (flag == true) {
		if (stack.empty() == true) {
			cout << "True\n";
		}
		else {
			cout << "Error!!!\n";
		}
	}
	else {
		cout << "Error!!!\n";
	}

	return 0;
}