#pragma once
#include "Employee.h"
#include "Guard.h"
#include "Electrician.h"
#include "Accountant.h"

class Secretary :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    std::array<int, 3> birthday;
    //Rate of salary
    double salary_rate;

    //Languages known by Secretary
    std::vector<std::string> languages;

    //pointer to vector with ellectricians
    std::vector<Electrician>* electricians;
    //pointer to vector with guards
    std::vector<Guard>* guards;
    //pointer to Accountant
    Accountant* accountant;

public:
//BASE
//CHANGERS
    //change name
    bool ch_name() override;
    //change surname
    bool ch_surname() override;
    //change partonymic
    bool ch_patronymic() override;

    //change salary
    void ch_salary(double slry) override;
    //change Rate of salary
    bool ch_salary_rate(double slry_rate) override;

    //Change bitrthday format(dd.mm.yyyy)
    bool ch_birthday() override;
//CHANGERS

//GETTERS
        //get full name in array: 0-name, 1-surname, 2-patronymic
    std::array<std::string, 3> get_fullname() override;

    //get salary
    int get_salary() override;
    //get rate of salary
    double get_salary_rate() override;

    //get birthday (tm struct)
    std::array<int, 3> get_birthday() override;
//GETTERS

    Secretary(std::array<std::string, 3> full_name, std::array<int, 3> birthday, std::vector<std::string> langs);
    Secretary();
//BASE
    
    //print languages
    void print_languages();
    //change languages
    void change_languages();

    //print all employers !!!TO TABLE!!!
    void print_employers();
    //print guards
    void print_guards();
    //print electricians
    void print_electricians();

    void pnt_initialization(std::vector<Electrician>* electricians, std::vector<Guard>* guards, Accountant* accountant);
};

