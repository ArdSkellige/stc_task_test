#define _CRT_SECURE_NO_WARNINGS
#include "person.h"
#include <string.h>

Person_t::Person_t(const char* _name, const char* _surname, const char* _middlename, size_t _age, SEX _sex) : age(_age), sex(_sex)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);

    surname = new char[strlen(_surname) + 1];
    strcpy(surname, _surname);

    middlename = new char[strlen(_middlename) + 1];
    strcpy(middlename, _middlename);
}

Person_t::Person_t(const Person_t& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);

    middlename = new char[strlen(other.middlename) + 1];
    strcpy(middlename, other.middlename);

    age = other.age;
    sex = other.sex;
}

Person_t::~Person_t()
{
    delete[] name;
    delete[] surname;
    delete[] middlename;
}

void Person_t::SetName(const char* _name)
{
    if(_name)
    {
        delete[] name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
}

void Person_t::SetSurname(const char* _name)
{
    if(_name)
    {
        delete[] surname;
        surname = new char[strlen(_name) + 1];
        strcpy(surname, _name);
    }
}

void Person_t::SetMiddlename(const char* _name)
{
    if(_name)
    {
        delete[] middlename;
        middlename = new char[strlen(_name) + 1];
        strcpy(middlename, _name);
    }
}

void Person_t::SetAge(int _age)
{
    if(_age >= 0 && _age <= 100)
    {
        age = _age;
    }
}

void Person_t::SetSex(int _sex)
{
    sex = static_cast<SEX>(_sex);
}

Person_t& Person_t::operator=(const Person_t& other)
{
    if (this != &other)
    {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        delete[] surname;
        surname = new char[strlen(other.surname) + 1];
        strcpy(surname, other.surname);

        delete[] middlename;
        middlename = new char[strlen(other.middlename) + 1];
        strcpy(middlename, other.middlename);

        age = other.age;
        sex = other.sex;
    }
    return *this;
}
