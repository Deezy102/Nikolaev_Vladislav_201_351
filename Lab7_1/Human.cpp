#include "Human.h"

Human::Human()
{
    surname = "";
    name = "";
    age = 0;
}

Human::Human(string a, string b, int c)
{
    surname = a;
    name = b;
    age = c;
}

Human::~Human()
{
}

string Human::get_surname()
{
    return surname;
}

string Human::get_name()
{
    return name;
}

int Human::get_age()
{
    return age;
}
std::ostream& operator<<(std::ostream& out, const Human& src)
{
    out << "Surname: " << src.surname << '\n'
        << "Name: " << src.name << '\n'
        << "Age: " << src.age << '\n';
    return out;
}