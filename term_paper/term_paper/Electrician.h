#pragma once
#include "Employee.h"

class Electrician :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    std::array<int, 3> birthday;

    //category of electrician
    int category;
    ////Permission category for work at height
    //int height_cat;

public:
//BASE
//CHANGERS
    //change name
    void ch_name() override;
    //change surname
    void ch_surname() override;
    //change partonymic
    void ch_patronymic() override;

    //change salary
    void ch_salary(double slry) override;

    //Change bitrthday format(dd.mm.yyyy)
    void ch_birthday() override;
//CHANGERS

//GETTERS
        //get full name in array: 0-name, 1-surname, 2-patronymic
    std::array<std::string, 3> get_fullname() override;

    //get salary
    int get_salary() override;

    //get birthday (tm struct)
    std::array<int, 3> get_birthday() override;
//GETTERS

    Electrician(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, int cat);
    Electrician();
//BASE
    
    //get category
    int get_category();
    //change catregory
    void ch_category();

    ////get height category
    //int get_height_cat();
    ////change height category
    //void ch_height_cat();
};

