#define _CRT_SECURE_NO_WARNINGS
#include "employee.h"
#include <string.h>

Employee_t::Employee_t(const char* _name, const char* _surname, const char* _middlename, size_t _age, SEX _sex, int _experience, const char* _phoneNum)
    : Person_t(_name, _surname, _middlename, _age, _sex), experience(_experience)
{
    phoneNumP = new char[strlen(_phoneNum) + 1];
    strcpy(phoneNumP, _phoneNum);
}

Employee_t::Employee_t(const Employee_t& other) : Person_t(other)
{
    phoneNumP = new char[strlen(other.phoneNumP) + 1];
    strcpy(phoneNumP, other.phoneNumP);
    experience = other.experience;
}

Employee_t::~Employee_t()
{
    delete[] phoneNumP;
}

void Employee_t::SetPhoneNumber(const char* num)
{
    if(num)
    {
        delete[] phoneNumP;
        phoneNumP = new char[strlen(num) + 1];
        strcpy(phoneNumP, num);
    }
}

Employee_t& Employee_t::operator=(const Employee_t& other)
{
    if (this != &other)
    {
        Person_t::operator=(other);

        delete[] phoneNumP;
        phoneNumP = new char[strlen(other.phoneNumP) + 1];
        strcpy(phoneNumP, other.phoneNumP);

        experience = other.experience;
    }
    return *this;
}
