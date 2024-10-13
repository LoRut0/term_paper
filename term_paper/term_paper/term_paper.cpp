#include "Includes.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Director director("Игорь", "Пеганов", "Николаевич", 200);
    director.print_employers();
}
