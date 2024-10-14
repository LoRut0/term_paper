#include "ControlMenu.h"

ControlMenu::ControlMenu() {
    read_flag = 0;
}

void ControlMenu::read_from_file(){
    if (read_flag) {
        std::cout << "Файл уже был прочитан" << std::endl;
        return;
    }
    FILE* file;
    fopen_s(&file, "input.txt", "r");
    if (file == 0) {
        std::cout << "Файл не открылся" << std::endl;
        return;
    }

    std::vector<std::string> input_vector;
    char ch;
    while ((ch = getc(file)) != EOF) {
        fseek(file, -1, 1);
        std::string read;
        while ((ch = getc(file)) != '\n') {
            read.push_back(ch);
        }
        input_vector.push_back(read);
    }
    fclose(file);

    for (std::string str)

    read_flag = 1;
    return;
}

inline void ControlMenu::print_name(std::array<std::string, 3> name) {
    std::cout << name[0] << ' ' << name[1] << ' ' << name[2] << ' ';
    return;
}

inline void ControlMenu::print_birthday(std::array<int, 3> birthday) {
    std::cout << birthday[0] << '.' << birthday[1] << '.' << birthday[2] << ' ';
    return;
};

int ControlMenu::print_companies() {
    int iter(1);
    if (directors_n_companies.size() == 0) {
        std::cout << "Компании ещё созданы" << std::endl;
        return 0;
    }
    for (Director* director : directors_n_companies) {
        std::cout << '(' << iter << ") " << "Название компании: " << director->get_company_name() << std::endl;
        std::cout << "Директор: "; print_name(director->get_fullname()); print_birthday(director->get_birthday());
        std::cout << std::endl;
    }
}

void ControlMenu::start() {
    bool flag = true;
    while (flag) {
        system("cls");
        std::cout << "Меню:\n(esc) Выйти\n(1) Чтение из подготовленного файла\n(2) Добавить новую компанию\n";

        int options_num = 2; //number of options in choice
        if (directors_n_companies.size() > 0) {
            std::cout << "(3) Вывести компании и их директоров\n";
            options_num = 3;
        }

        switch (Input::choice(1, options_num))
        {
        case 1: 
            read_from_file();
            break;
        case 2: {
            Director* new_director = new Director("Ivanov", "Ivan", "Ivanovich", { 1, 1, 1 }, "Kontora");
            new_director->change_company_name();
            new_director->ch_name();
            new_director->ch_surname();
            new_director->ch_patronymic();
            new_director->ch_birthday();

            directors_n_companies.push_back(new_director);
            break;
        }
        case 3:
            print_companies();
            break;
        case -1:
            flag = false;
            break;
        default:
            break;
        }
    }
}