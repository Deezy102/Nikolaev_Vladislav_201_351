#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <utility>

using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::list;
using std::ifstream;

bool Comparing(pair<int, string> left, pair<int, string> right) {
	if (left.first < right.first) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int group;
	string surname;
	list<pair<int, string>> studlist;
	list<pair<int, string>>::iterator iter;

	ifstream studfile("students_list.txt", std::ios::in);
	if (!studfile.is_open()) {
		cout << "try again\n";
	}
	else {
		while (!studfile.eof()) {
			int group = 0;
			string surname;
			studfile >> group >> surname;
			studlist.push_back(make_pair(group, surname));
			
		}
		
	}

	studlist.sort(Comparing);
	for (iter = studlist.begin(); iter != studlist.end(); iter++) {
		cout << iter->first << "  "<<iter->second << std::endl;
	}
	return 0;
}
