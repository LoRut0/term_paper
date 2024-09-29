#pragma once


#include "Employee.h"


class Accountant :
    public Employee
{
    //0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician
    double salary_rate[5];
public:
    Accountant(std::string, std::string, std::string, int);

    void get_salary_rate();
    void ch_salary_rate();

    int salary_calculation(int);
};

