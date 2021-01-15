#include <set>
#include <iostream>
#include <utility>

using std::set;
using std::cout;
using std::cin;


int main() {
	
	
	set<std::pair<int, int>> setlist; //сет пар <id, result>
	int choice;
	int n;

	while (true) {
		cout << "1. Input results\n2. Output results\n3. Exit\n";
		cin >> choice;
		switch(choice){
		case 1: {
			set<std::pair<int, int>>::iterator j;
			cout << "How many times has the test been solved:";
			cin >> n;
			for (int i = 0; i < n; i++) {
				bool flag = false;
				int id, score;
				cin >> id >> score;
				for (auto j = setlist.begin(); j != setlist.end(); j++) {
					if (j->first == id) {
						flag = true; //проверка есть ли в сете уже такой айди
					}
				}
				if (flag == false) { //если нет то добавляем пару айди и результат
					setlist.insert(std::make_pair(id, score));
				}
			}
			break;
		}
		case 2: {
			//вывод списка айди и результатов за тест
			set<std::pair<int, int>>::iterator i;
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