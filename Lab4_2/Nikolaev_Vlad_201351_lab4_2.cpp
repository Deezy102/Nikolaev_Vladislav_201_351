#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;
using std::ifstream;
using std::ofstream;

string file_format(const string file_path_full) {
    string format;
    format.assign(file_path_full, file_path_full.rfind('.'), file_path_full.length());
    return format;
}
string file_name(const string file_path_full) {
    string name;
    name.assign(file_path_full, file_path_full.rfind(char(92)) + 1, file_path_full.length());
    name.erase(name.rfind('.'), name.length() - name.rfind('.'));
    return name;
}
string file_path_f(const string file_path_full) {
    string path;
    path.assign(file_path_full, 0, file_path_full.rfind(char(92)));
    return path;
}
char file_disk(const string file_path_full) {
    const char* disk;
    disk = file_path_full.c_str();
    return disk[0];
}
bool file_rename(string* file_path_full) {
    string buf = *file_path_full; 
    string rename;
    cout << "Введите новое название: \n";
    getline(cin, rename);
    if (file_format(*file_path_full) != "-1") {
        if (rename != file_name(*file_path_full)) {
            buf.replace(buf.find(file_name(*file_path_full)), file_name(*file_path_full).length(), rename);
            *file_path_full = buf;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    
}
bool file_copy(const string file_path_full) {
    
    string copy_path = file_path_full;
    string buf_copy;
    ifstream file(file_path_full, ifstream::in); 
    if (file.is_open() == true) {
        copy_path.replace(file_path_full.rfind('.'), file_path_full.length() - file_path_full.rfind('.'), "_copy.txt");
        cout << copy_path << endl;
        ofstream copy;
        copy.open(copy_path, ofstream::out);
        if (copy.is_open() == true) {
            while (getline(file, buf_copy)) {
                copy << buf_copy << endl;
            }
            file.close();
            copy.close();
            return true;
        }
        else {
           return false;
        }
       
        
    }
    else {
        return false;
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string file_path;
    int choice = 0;
    while (true)
    {
        cout << "Что вы хотите выполнить?\n" << "1. Расширение\n" << "2. Название\n" << "3. Расположение \n"
            << "4. Диск\n" << "5. Переименовать файл \n" << "6. Создать копию\n" << "7. Exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            string format;
            cout << "Введите полное расположение файла: \n";
            //C:\Users\vlad1\Desktop\piu\app.exe
            getline(cin, file_path);
            format = file_format(file_path);
            cout << format << endl;
            break;
        }
        case 2: {
            
            string name;
            cout << "Введите полное расположение файла: \n";
            getline(cin, file_path);
            name = file_name(file_path);
            cout << name << endl;
            break;
        }
        case 3: {
            string path;
            cout << "Введите полное расположение файла: \n";
            getline(cin, file_path);
            path = file_path_f(file_path);
            cout << path << endl;
            break;
        }
        case 4: {
            char disk;
            cout << "Введите полное расположение файла: \n";
            getline(cin, file_path);
            disk = file_disk(file_path);
            cout << disk << endl;
            break;
        }
        case 5: {
            bool flag;
            cout << "Введите полное расположение файла: \n";
            getline(cin, file_path);
            flag = file_rename(&file_path);
            if (flag == true) {
                cout << file_path << endl;
            }
            else {
                cout << "Ошибка. Повторите операцию заново\n    ";
            }
            break;
        }
        case 6: {
            bool flag;
            cout << "Введите полное расположение файла: \n";
            getline(cin, file_path);
            flag = file_copy(file_path);
            if (flag == true) {
                cout << "Копирование завершено\n";
            }
            else {
                cout << "Ошибка\n";
            }
            break;
        }
        case 7: {
            cout << "BB\n";
            return 0;
        }
        default: {
            cout << "Выберите действие еще раз\n";
        }

        }

    }
    return 0;
}
