#include "ControlMenu.h"
#include "iomanip"

ControlMenu::ControlMenu() {
    read_flag = 0;
}


std::array<int, 3> ControlMenu::str_to_date(std::string str_date) {
    std::array<std::string, 3> date;
    date[0].push_back(str_date[0]);
    date[0].push_back(str_date[1]);
    date[1].push_back(str_date[3]);
    date[1].push_back(str_date[4]);
    date[2].push_back(str_date[6]);
    date[2].push_back(str_date[7]);
    date[2].push_back(str_date[8]);
    date[2].push_back(str_date[9]);
    std::array<int, 3> int_date{ std::stoi(date[0]),  std::stoi(date[1]), std::stoi(date[2]) };
    return int_date;
}

void ControlMenu::read_from_file(){
    if (read_flag) {
        std::cout << "���� ��� ��� ��������" << std::endl;
        return;
    }
    FILE* file;
    fopen_s(&file, "input.txt", "r");
    if (file == 0) {
        std::cout << "���� �� ��������" << std::endl;
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

    for (std::string str : input_vector) {
        if (str.size() > 2 and str[0] == '/' and str[1] == '/') continue; //skip comments
        
        unsigned n = 0;
        std::string job;
        for (n; n < str.size(); n++) {
            if (str[n] == ';') break;
            job.push_back(str[n]);
        }

        if (job == "Director") {
            std::array<std::string, 3> full_name;
            std::array<int, 3> birthday; std::string str_date;
            std::string cmpny_name;
            for (int i = 0; i < 3; i++) {
                n += 2;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    full_name[i].push_back(str[n]);
                }
            }
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                str_date.push_back(str[n]);
            }
            birthday = str_to_date(str_date);
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                cmpny_name.push_back(str[n]);
            }
            Director* new_director = new Director(full_name, birthday, cmpny_name);
            directors_n_companies.push_back(new_director);
        }
        else if (job == "Accountant") {
            std::array<std::string, 3> full_name;
            std::array<int, 3> birthday; std::string str_date;
            std::string cmpny_name;
            std::array<int, 5> base_slry;
            std::array<double, 5> slry_rate;
            for (int i = 0; i < 3; i++) {
                n += 2;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    full_name[i].push_back(str[n]);
                }
            }
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                str_date.push_back(str[n]);
            }
            birthday = str_to_date(str_date);
            for (int i = 0; i < 5; i++) {
                n += 2;
                std::string temp;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    temp.push_back(str[n]);
                }
                base_slry[i] = std::stoi(temp);
            }
            for (int i = 0; i < 5; i++) {
                n += 2;
                std::string temp;
                for (n; n < str.size(); n++) {
                    if (str[n] == ';') break;
                    temp.push_back(str[n]);
                }
                slry_rate[i] = std::stod(temp);
            }
            Accountant accountant(full_name, birthday, base_slry, slry_rate);
            directors_n_companies.back()->hire_employers(accountant);
        }
        else if (job == "Secretary") {
            std::array<std::string, 3> full_name;
            std::array<int, 3> birthday; std::string str_date;
            std::vector<std::string> langs;
            for (int i = 0; i < 3; i++) {
                n += 2;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    full_name[i].push_back(str[n]);
                }
            }
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                str_date.push_back(str[n]);
            }
            birthday = str_to_date(str_date);
            while (n < str.size()) {
                n += 2;
                std::string temp;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    temp.push_back(str[n]);
                }
                if (temp.size() != 0) langs.push_back(temp);
            }
            Secretary secretary(full_name, birthday, langs);
            directors_n_companies.back()->hire_employers(secretary);
        }
        else if (job == "Guard") {
            std::array<std::string, 3> full_name;
            std::array<int, 3> birthday; std::string str_date;
            int shift;
            std::string weapon;
            for (int i = 0; i < 3; i++) {
                n += 2;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    full_name[i].push_back(str[n]);
                }
            }
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                str_date.push_back(str[n]);
            }
            birthday = str_to_date(str_date);
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                weapon.push_back(str[n]);
            }
            n += 2;
            std::string temp;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                temp.push_back(str[n]);
            }
            shift = std::stoi(temp);
            Guard guard(full_name, birthday, weapon, shift);
            directors_n_companies.back()->hire_employers(guard);
        }
        else if (job == "Electrician") {
            std::array<std::string, 3> full_name;
            std::array<int, 3> birthday; std::string str_date;
            int cat;
            for (int i = 0; i < 3; i++) {
                n += 2;
                for (n; n < str.size(); n++) {
                    if (str[n] == ',' or str[n] == ';') break;
                    full_name[i].push_back(str[n]);
                }
            }
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                str_date.push_back(str[n]);
            }
            birthday = str_to_date(str_date);
            std::string temp;
            n += 2;
            for (n; n < str.size(); n++) {
                if (str[n] == ';') break;
                temp.push_back(str[n]);
            }
            cat = std::stoi(temp);
            Electrician electrician(full_name, birthday, cat);
            directors_n_companies.back()->hire_employers(electrician);
        }
    }
    read_flag = 1;
    std::cout << "������ � ����� �������" << std::endl;
    return;
}

inline void ControlMenu::print_name(std::array<std::string, 3> name) {
    std::cout << name[0] << ' ' << name[1] << ' ' << name[2] << ' ';
    return;
}

inline void ControlMenu::print_birthday(std::array<int, 3> birthday) {
    std::cout << std::right << std::setfill('0') << std::setw(2)
        << birthday[0] << '.' << std::setw(2) << birthday[1] << '.' << std::setw(2) << birthday[2] << ' ';
    return;
};

inline void ControlMenu::print_comp(int num) {
    Director* director = directors_n_companies[num];
    std::cout << "�������� ��������: " << director->get_company_name() << std::endl;
    std::cout << "��������: "; print_name(director->get_fullname()); print_birthday(director->get_birthday());
    std::cout << std::endl;
}

int ControlMenu::print_companies() {
    int iter(1);
    if (directors_n_companies.size() == 0) {
        std::cout << "�������� ��� �� �������" << std::endl;
        return 0;
    }
    for (Director* director : directors_n_companies) {
        std::cout << '(' << iter++ << ") " << "�������� ��������: " << director->get_company_name() << std::endl;
        std::cout << "��������: "; print_name(director->get_fullname()); print_birthday(director->get_birthday());
        std::cout << std::endl;
    }
    return iter;
}

void ControlMenu::start() {
    bool flag1 = true;
    while (flag1) {
        system("cls");
        std::cout << "����:\n(esc) �����\n(1) ������ �� ��������������� �����\n(2) �������� ����� ��������\n";

        int options_num = 2; //number of options in choice
        if (directors_n_companies.size() > 0) {
            std::cout << "(3) ������� �������� � �� ���������� (�����)\n";
            options_num = 3;
        }

        switch (Input::choice(1, options_num))
        {
        case 1: 
            read_from_file();
            system("pause");
            break;
        case 2: {
            Director* new_director = new Director({ " ", " ", " " }, { 1, 1, 1 }, "Kontora");
            if (new_director->change_company_name()) break;
            std::cout << "��������:\n";
            if (new_director->ch_name()) break;
            if (new_director->ch_surname()) break;
            if (new_director->ch_patronymic()) break;
            if (new_director->ch_birthday()) break;

            directors_n_companies.push_back(new_director);
            break;
        }
        case 3: {
            std::cout << std::endl;
            int num_of_comps = print_companies() - 1;
            std::cout << "��������: ";
            int choice = Input::int_(1, num_of_comps);
            if (choice == INT_MIN) break; choice--;
            std::cout << std::endl;

            print_comp(choice);

            Director* director = directors_n_companies[choice];
            Accountant* accountant = NULL;
            Secretary* secretary = NULL;
            std::vector<Guard>* guards = NULL;
            std::vector<Electrician>* electricians = NULL;

            director->get_pnts(&accountant, &secretary, &guards, &electricians);

            bool flag2(true);
            while (flag2) {
                system("cls");
                std::cout << director->get_company_name() << std::endl;
                std::cout << "����:\n(1) ��������\n(2) ���������\n(3) ���������\n(4) ��������\n(5) ��������\n";
                switch (Input::choice(1, 5))
                {
                case 1:
                {
                    bool flag3(true);
                    while (flag3) {
                        system("cls");
                        std::cout << director->get_company_name() << std::endl;
                        std::cout << "��������: "; print_name(director->get_fullname()); print_birthday(director->get_birthday()); std::cout << "\n";
                        std::cout << "����:\n(1) ������� �����������\n(2) ������� �����������\n(3) ������ �����������\n(4) ������� �������� ��������\n";
                        std::cout << "(5) ������� ���\n(6) ������� �������\n(7) ������� ��������\n";
                        switch (Input::choice(1, 7))
                        {
                        case 1:
                            director->print_employers();
                            system("pause");
                            break;
                        case 2:
                            director->fire_employers();
                            director->get_pnts(&accountant, &secretary, &guards, &electricians);
                            //system("pause");
                            break;
                        case 3:
                            director->hire_employers();
                            director->get_pnts(&accountant, &secretary, &guards, &electricians);
                            //system("pause");
                            break;
                        case 4:
                            director->change_company_name();
                            //system("pause");
                            break;
                        case 5:
                            director->ch_name();
                            break;
                        case 6:
                            director->ch_surname();
                            break;
                        case 7:
                            director->ch_patronymic();
                            break;
                        case -1:
                            flag3 = false;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    if (secretary == NULL) {
                        std::cout << "��������� �����������" << std::endl;
                        system("pause");
                        break;
                    }
                    bool flag3(true);
                    while (flag3) {
                        system("cls");
                        std::cout << director->get_company_name() << std::endl;
                        std::cout << "���������: "; print_name(secretary->get_fullname()); print_birthday(secretary->get_birthday()); std::cout << "\n";
                        std::cout << "����\n(1) �����, �������� ������� ���������\n(2) ������� ���� ����������� �������� � �������\n(3) ������� ���� ���������� � �������\n(4) ������� ���� ���������� � �������\n";
                        std::cout << "(5) ������� ���\n(6) ������� �������\n(7) ������� ��������\n";
                        switch (Input::choice(1, 7))
                        {
                        case 1:
                            secretary->change_languages();
                            //system("pause");
                            break;
                        case 2:
                            secretary->print_employers();
                            system("pause");
                            break;
                        case 3:
                            secretary->print_guards();
                            system("pause");
                            break;
                        case 4:
                            secretary->print_electricians();
                            system("pause");
                            break;
                        case 5:
                            secretary->ch_name();
                            break;
                        case 6:
                            secretary->ch_surname();
                            break;
                        case 7:
                            secretary->ch_patronymic();
                            break;
                        case -1:
                            flag3 = false;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (accountant == NULL) {
                        std::cout << "��������� �����������" << std::endl;
                        system("pause");
                        break;
                    }
                    bool flag3(true);
                    while (flag3) {
                        system("cls");
                        std::cout << director->get_company_name() << std::endl;
                        std::cout << "���������: "; print_name(accountant->get_fullname()); print_birthday(accountant->get_birthday()); std::cout << "\n";
                        std::cout << "����\n(1) �����\n(2) ������\n(3) ������� ������� ��������\n";
                        std::cout << "(4) ������� ���\n(5) ������� �������\n(6) ������� ��������\n";
                        switch (Input::choice(1, 7))
                        {
                        case 1:
                            accountant->ch_base_salary();
                            salary_update(&electricians, &guards, &secretary, &director, &accountant);
                            break;
                        case 2:
                            accountant->ch_salary_rate();
                            salary_update(&electricians, &guards, &secretary, &director, &accountant);
                            break;
                        case 3: {
                            int secret;
                            secretary ? secret = 1: secret = 0;
                            double avg_slry = accountant->average_salary(guards->size(), electricians->size(), secret);
                            std::cout << "������� ��������: " << avg_slry << std::endl;
                            system("pause");
                            break;
                        }
                        case 4:
                            accountant->ch_name();
                            break;
                        case 5:
                            accountant->ch_surname();
                            break;
                        case 6:
                            accountant->ch_patronymic();
                            break;
                        case -1:
                            flag3 = false;
                            break;
                        default:
                            break;
                        }
                    }
                }
                case 4:
                {
                    if (guards->size() == 0) {
                        std::cout << "��������� �����������" << std::endl;
                        system("pause");
                        break;
                    }
                    bool flag3(true);
                    while (flag3) {
                        system("cls");
                        std::cout << director->get_company_name() << std::endl;
                        int num = director->print_guards();
                        std::cout << "������� ����� ���������: "; int guard_choice = Input::int_(1, num);
                        if (guard_choice == INT_MIN) {
                            flag3 = false;
                            break;
                        }
                        guard_choice--;
                        bool flag4 = true;
                        while (flag4) {
                            system("cls");
                            std::cout << director->get_company_name() << std::endl;
                            std::cout << "��������: "; print_name((*guards)[guard_choice].get_fullname()); print_birthday((*guards)[guard_choice].get_birthday()); std::cout << "\n";
                            std::cout << "����. ����������: " << (*guards)[guard_choice].get_weapon() << std::endl;
                            std::string shift;
                            switch ((*guards)[guard_choice].get_shift())
                            {
                            case 1: 
                                shift = "22:00-06:00";
                                break;
                            case 2:
                                shift = "06:00-14:00";
                                break;
                            case 3:
                                shift = "14:00-22:00";
                                break;
                            default:
                                break;
                            }
                            std::cout << "�����: " << shift << std::endl;
                            std::cout << "����\n(1) ������� ����. ����������\n(2) �������� �����\n";
                            std::cout << "(3) ������� ���\n(4) ������� �������\n(5) ������� ��������\n";
                            switch (Input::choice(1, 5))
                            {
                            case 1:
                                (*guards)[guard_choice].ch_weapon();
                                break;
                            case 2:
                                (*guards)[guard_choice].ch_shift();
                                break;
                            case 3:
                                (*guards)[guard_choice].ch_name();
                                break;
                            case 4:
                                (*guards)[guard_choice].ch_surname();
                                break;
                            case 5:
                                (*guards)[guard_choice].ch_patronymic();
                                break;
                            case -1:
                                flag4 = false;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                }
                case 5:
                {
                    if (electricians->size() == 0) {
                        std::cout << "��������� �����������" << std::endl;
                        system("pause");
                        break;
                    }
                    bool flag3(true);
                    while (flag3) {
                        system("cls");
                        std::cout << director->get_company_name() << std::endl;
                        int num = director->print_electricians();
                        std::cout << "������� ����� ���������: "; int elec_choice = Input::int_(1, num);
                        if (elec_choice == INT_MIN) {
                            flag3 = false;
                            break;
                        }
                        elec_choice--;
                        bool flag4 = true;
                        while (flag4) {
                            system("cls");
                            std::cout << director->get_company_name() << std::endl;
                            std::cout << "��������: "; print_name((*electricians)[elec_choice].get_fullname()); print_birthday((*electricians)[elec_choice].get_birthday()); std::cout << "\n";
                            std::cout << "������: " << (*electricians)[elec_choice].get_category() << std::endl;
                            std::cout << "����\n(1) ������� ������\n";
                            std::cout << "(2) ������� ���\n(3) ������� �������\n(4) ������� ��������\n";
                            switch (Input::choice(1, 5))
                            {
                            case 1:
                                (*electricians)[elec_choice].ch_category();
                                break;
                            case 2:
                                (*electricians)[elec_choice].ch_name();
                                break;
                            case 3:
                                (*electricians)[elec_choice].ch_surname();
                                break;
                            case 4:
                                (*electricians)[elec_choice].ch_patronymic();
                                break;
                            case -1:
                                flag4 = false;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                }
                case -1:
                    flag2 = false;
                    break;
                default:
                    break;
                }
            }
            //secretary->print_employers();
            //system("pause");
            break;
        }
        case -1:
            flag1 = false;
            break;
        default:
            break;
        }
    }
}   

void ControlMenu::salary_update(std::vector<Electrician>** electricians, std::vector<Guard>** guards, Secretary** secretary, Director** director, Accountant** accountant) 
{
    std::array<int, 5> base = (*accountant)->get_base_salary();
    std::array<double, 5> rate = (*accountant)->get_salary_rate();
    std::array<double, 5> salary{ base[0] * rate[0], base[1] * rate[1], base[2] * rate[2], base[3] * rate[3], base[4] * rate[4] };
    /*Base salaries
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    (*director)->ch_salary(salary[0]);
    (*accountant)->ch_salary(salary[1]);
    if (*secretary) (*secretary)->ch_salary(salary[2]);
    for (int i = 0; i < (*guards)->size(); i++) (**guards)[i].ch_salary(salary[3]);
    for (int i = 0; i < (*electricians)->size(); i++) (**electricians)[i].ch_salary(salary[3]);
    return;
}