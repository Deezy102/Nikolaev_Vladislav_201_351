#include <map>
#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::ifstream;

int main() {
	
	map<string, int>::iterator iter;
	map<string, int> text_map;
	int total = 0;
	ifstream textfile("text_example.txt", std::ios::in);
	if (!textfile.is_open()) {
		cout << "try again\n";
	}
	else {
		while (!textfile.eof()) {

			string simple;
			textfile >> simple;
			
			if ((!((simple[0] <= 'Z' && simple[0] >= 'А')||(simple[0] <= 'z' && simple[0] >= 'a')))||((simple[0]=='"')||(simple[0] == '('))) {
				simple.erase(0);
			}
			if (simple.empty()) {
				continue;
			}
			if (!(simple[0] <= 'z' && simple[0] >= 'a')) {
				simple[0] = char(int(simple[0]) + 32);
			}
			if (!(simple[simple.length()-1] <= 'z' && simple[simple.length()-1] >= 'a')) {
				simple.erase(simple.length()-1);
			}
			if (simple.empty()){
				continue;
			}
			if (text_map.count(simple) != 0) {
				text_map[simple]++;
			}
			else {
				text_map.insert({ simple, 1 });
			}

			total++;

		}
	}
	cout << "Total words is " << total << std::endl;
	for (iter = text_map.begin(); iter != text_map.end(); iter++) {
		cout << (*iter).first <<  "___" << iter->second / (total / 100.) << '%' << std::endl;
	}
	return 0;
}