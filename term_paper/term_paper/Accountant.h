#pragma once


#include "Employee.h"


class Accountant :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    tm birthday;

    //Базовый оклад
    int base_salary;
    //0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician
    double salary_rate[5];
public:
    //change name
    void ch_name(std::string) override;
    //change surname
    void ch_surname(std::string) override;
    //change partonymic
    void ch_patronymic(std::string) override;
    //change salary
    void ch_salary(int) override;

    //get full name in array: 0-name, 1-surname, 2-patronymic
    std::array<std::string, 3> get_fullname() override;
    //get salary
    int get_salary() override;

    //Change bitrthday format(dd.mm.yyyy)
    void ch_birthday() override;
    //get birthday (tm struct)
    tm get_birthday() override;

    Accountant(std::string, std::string, std::string, int);

    void get_salary_rate();
    void ch_salary_rate();

    int ch_base_salary();
    int get_base_salary();

    int salary_calculation(int);
};

