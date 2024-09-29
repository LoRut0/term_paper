#pragma once
#include <vector>

#include "Employee.h"
#include "Guard.h"
#include "Electrician.h"

class Secretary :
    public Employee
{


public:
    Secretary(std::string, std::string, std::string, int);

    void print_employers();
    void print_guards(std::vector<Guard>);
    void print_electricians(std::vector<Electrician>);
};

