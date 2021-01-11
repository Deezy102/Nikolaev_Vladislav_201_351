#include <set>
#include <iostream>
#include <utility>

using std::set;
using std::cout;
using std::cin;


int main() {
	
	
	set<std::pair<int, int>> setlist;
	int choice;
	int n;

	while (true) {
		cout << "1. Input results\n2. Output results\n3. Exit\n";
		cin >> choice;
		switch(choice){
		case 1: {
			cout << "Input number of students:";
			cin >> n;
			for (int i = 0; i < n; i++) {
				bool flag = false;
				int id, score;
				cin >> id >> score;
				for (auto i = setlist.begin(); i != setlist.end(); i++) {
					if (i->first == id) {
						flag = true;
					}
				}
				if (flag == false) {
					setlist.insert(std::make_pair(id, score));
				}
			}
			break;
		}
		case 2: {
			for (auto i = setlist.begin(); i != setlist.end(); i++) {
				cout << "Student's ID:" << i->first << " Score:" << i->second << std::endl;
			}
			break;
		}
		case 3: {
			cout << "BB\n";
			return 0;;
		}
		default: {

			break;
		}
		}
	}
	return 0;
}