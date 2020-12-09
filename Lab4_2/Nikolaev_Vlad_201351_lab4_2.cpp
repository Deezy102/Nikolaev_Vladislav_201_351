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
    //строка формат присваивает часть строки файл_паф_фул
    format.assign(file_path_full, file_path_full.rfind('.'), file_path_full.length());
    return format;
}
string file_name(const string file_path_full) {
    string name;
    //строка нейм присвает имя и расширение файла
    name.assign(file_path_full, file_path_full.rfind(char(92)) + 1, file_path_full.length());
   //из строки нейм удаляется расширение файла
    name.erase(name.rfind('.'), name.length() - name.rfind('.'));
    return name;
}
string file_path_f(const string file_path_full) {
    string path;
    //строка паф присваивает строку с 0 до n-ного символа строки
    path.assign(file_path_full, 0, file_path_full.rfind(char(92))-1);
    return path;
}
char file_disk(const string file_path_full) {
    const char* disk;
    //переводим стринг в си-стринг и возвращаем нулевой элемент символьного массива
    disk = file_path_full.c_str();
    return disk[0];
}
bool file_rename(string* file_path_full) {
    string buf = *file_path_full; //принимаем в буфер путь файла
    string rename; //строка под новое название
    cout << "Введите новое название: \n";
    getline(cin, rename);
    if (file_format(*file_path_full) != "-1") {//проверка есть ли название файла в пути файла
        if (rename != file_name(*file_path_full)) {//проверка на совпадение старого и нового названия 
            //заменяем старое название в пути файла на новое
            buf.replace(buf.find(file_name(*file_path_full)), file_name(*file_path_full).length(), rename);
            *file_path_full = buf; //изменяем изначальный путь файла 
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
    
    string copy_path = file_path_full; //помещаем путь файла в строку для пути копии файла
    string buf_copy; //буфер для передачи данных из оригинала в копию
    ifstream file(file_path_full, ifstream::in); //файловый ввод по пути из файл_паф_фул с режимом открытия на чтение
    if (file.is_open() == true) {//проверка открыт ли оригинал 
        //изменяем название в пути для копии 
        copy_path.replace(file_path_full.rfind(char(92)), file_path_full.rfind('.') - file_path_full.rfind(char(92)), file_name(file_path_full) + "_copy");
        
        cout << copy_path << endl;
        //создание объекта класса файлового вывода
        ofstream copy; 
        copy.open(copy_path, ofstream::out); //создаем и открываем копию с режимом для записи
        if (copy.is_open() == true) {//проверяем открылась ли копия 
            while (getline(file, buf_copy)) {
                copy << buf_copy << endl;//пока считываются строки из оригинала вкладываем их в копию
            }
            //закрываем оба файла
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
            //C:\\Users\\vlad1\\Desktop\\piu\\test.txt
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
            getline(cin, file_path);//C:\Users\\vlad1\\Desktop\\piu\\test.txt
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
