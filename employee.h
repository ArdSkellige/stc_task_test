#ifndef EMPLOYEE_T_H
#define EMPLOYEE_T_H

#include "person.h"

class Employee_t : public Person_t
{
private:
    int experience;
    char* phoneNumP;
public:
    Employee_t(const char* _name = "Undef", const char* _surname = "Undef", const char* _middlename = "Undef", size_t _age = 18, SEX _sex = MAN, int _experience = 0, const char* _phoneNum = "8(800)222-35-35");
    Employee_t(const Employee_t& other);
    virtual ~Employee_t();

    void SetPhoneNumber(const char* num);
    const char* GetPhoneNumber() const { return phoneNumP; }
    void SetExperience(int exper) { if(exper >= 0){ experience = exper; } }
    int GetExperience() const { return experience; }

    Employee_t& operator=(const Employee_t& other);
};

#endif // EMPLOYEE_T_H
