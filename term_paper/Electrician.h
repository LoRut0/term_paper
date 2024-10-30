#pragma once
#include "Employee.h"

class Electrician :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    double salary;
    //Birthday
    std::array<int, 3> birthday;
    //Rate of salary
    double salary_rate;
    //category of electrician
    int category;

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

    //Change bitrthday format(dd.mm.yyyy)
    bool ch_birthday() override;
//CHANGERS

//GETTERS
        //get full name in array: 0-name, 1-surname, 2-patronymic
    std::array<std::string, 3> get_fullname() override;

    //get salary
    double get_salary() override;

    //get birthday (tm struct)
    std::array<int, 3> get_birthday() override;
//GETTERS

    Electrician(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, int cat);
    Electrician();
//BASE
    
    //get category
    int get_category();
    //change catregory
    bool ch_category();

    ////get height category
    //int get_height_cat();
    ////change height category
    //void ch_height_cat();
};

