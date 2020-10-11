#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Задание 1
    cout << "Nikolaev Vladislav Andreevich, 201-351" << endl;
    //Задание 2
    cout << "min int = " << INT_MIN << ", max int = " << INT_MAX << ", size of int = " << sizeof(int) << endl;
    cout << "min unsigned int = 0" << ", max unsigned int = " << UINT_MAX << ", size of unsigned int = " << sizeof(unsigned int) << endl;
    cout << "min short = " << SHRT_MIN << ", max short = " << SHRT_MAX << ", size of short = " << sizeof(short int) << endl;
    cout << "min unsigned short = 0" << ", max unsigned short = " << USHRT_MAX << ", size of unsigned short = " << sizeof(unsigned short) << endl;
    cout << "min long = " << LONG_MIN << ", max long = " << LONG_MAX << ", size of long = " << sizeof(long int);
    cout << "min long long = " << LLONG_MIN << ", max long long= " << LLONG_MAX << ", size of long long = " << sizeof(long long) << endl;
    cout << "min double = " << DBL_MIN << ", max double = " << DBL_MAX << ", size of double = " << sizeof(double) << endl;
    cout << "min char = " << CHAR_MIN << ", max char = " << CHAR_MAX << ", size of char = " << sizeof(char) << endl;
    cout << "min bool = 0" << ", max bool = 255" << ", size of bool = " << sizeof(bool) << endl;
    //Задание 3
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "In binary form: " << std::bitset<16>(n) << endl;
    cout << "In hexadecimal form: " << std::hex << n << endl;
    cout << "Boolean: " << bool(n) << endl;
    cout << "Char: " << char(n) << endl;
    //Задание 4
    double a; double b;
    cout << "Enter a * x = b:" << endl;
    cin >> a >> b;
    cout << a << " * x = " << b << endl;
    cout << "x = " << b << "/" << a << endl;
    cout << "x = " << b / a << endl;
    cout << "Root of equation: " << b / a << endl;
    //Задание 5
    int y; int y1;
    cout << "Enter the coordinates of the segment: ";
    cin >> y >> y1;
    cout << endl << "The middle of the line is at the point with the coordinate " << (y + y1) / 2.;

    return 0;
}
