//figure.cpp описание класса figure
#include "classes.h"

const vector<vector<vector<array<short, 2>>>> figure_position_example{
    { {{4, 0}, {4, 1}, {5, 0}, {5, 1}}, {{4, 0}, {4, 1}, {5, 0}, {5, 1}}, {{4, 0}, {4, 1}, {5, 0}, {5, 1}}, {{4, 0}, {4, 1}, {5, 0}, {5, 1}} },//O
    { {{4, 3}, {4, 2}, {4, 1}, {4, 0}}, {{3, 1}, {4, 1}, {5, 1}, {6, 1}}, {{4, 3}, {4, 2}, {4, 1}, {4, 0}}, {{4, 1}, {5, 1}, {6, 1}, {7, 1}} },//I
    { {{4, 0}, {4, 1}, {5, 1}, {5, 2}}, {{3, 2}, {4, 2}, {4, 1}, {5, 1}}, {{4, 0}, {4, 1}, {5, 1}, {5, 2}}, {{3, 2}, {4, 2}, {4, 1}, {5, 1}} },//Z
    { {{4, 2}, {4, 1}, {5, 1}, {5, 0}}, {{3, 1}, {4, 1}, {4, 2}, {5, 2}}, {{4, 2}, {4, 1}, {5, 1}, {5, 0}}, {{4, 1}, {5, 1}, {5, 2}, {6, 2}} },//S
    { {{4, 2}, {4, 1}, {4, 0}, {5, 0}}, {{3, 0}, {3, 1}, {4, 1}, {5, 1}}, {{4, 2}, {5, 2}, {5, 1}, {5, 0}}, {{3, 0}, {4, 0}, {5, 0}, {5, 1}} },//L
    { {{4, 0}, {5, 0}, {5, 1}, {5, 2}}, {{3, 1}, {3, 0}, {4, 0}, {5, 0}}, {{4, 0}, {4, 1}, {4, 2}, {5, 2}}, {{3, 1}, {4, 1}, {5, 1}, {5, 0}} },//J
    { {{3, 0}, {4, 0}, {5, 0}, {4, 1}}, {{4, 0}, {4, 1}, {4, 2}, {5, 1}}, {{3, 1}, {4, 1}, {5, 1}, {4, 0}}, {{4, 1}, {5, 0}, {5, 1}, {5, 2}} } //T
};

inline bool figure::find(vector <array<short, 2>> coordinates, array<short, 2> array) { //Многострадальная проверка на вхождение координат в массив.
    for (int i = 0; i < 4; i++) {
        if (coordinates[i] == array) return true;
    }
    return false;
}

figure::figure(short input_figure_num, short input_position)
{
    score = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 24; j++) {
            field[i][j] = false;
        }
    }

    figure_num = input_figure_num;
    position = input_position;

    vector <array<short, 2>> coordinates = figure_position_example[figure_num][position];

    y = 20;
    x = 4;

    for (int i = 0; i < y; i++) {
        coordinates[0][1]++;
        coordinates[1][1]++;
        coordinates[2][1]++;
        coordinates[3][1]++;
    }

    game_over = false;
    if (figure_spawn()) game_over = true;
}

inline bool figure::figure_spawn() {
    //!!!!!!!!!!!Необходимо ещё реализовать рандомное начальное положение, после того как будет написана функция вращения фигуры. 
    unsigned short num_figure = rand_int_input(0, 6);
    
    vector <array<short, 2>> coordinates = figure_position_example[figure_num][position];
    for (int i = 0; i < 4; i++) {
        coordinates[i][1] += 20;
    }

    if (physics(coordinates, field, position, figure_num, y, x)) return 1;
    return 0;
}

bool figure::collision_dwn() {
    for (int i = 0; i < 4; i++) {
        if (coordinates[i][1] == 0) return true;
    }

    for (int i = 0; i < 4; i++) {
        array<short, 2> array{ coordinates[i][0], coordinates[i][1] - 1 };
        bool flag = find(coordinates, array); //проверка, является ли столкновение столкновением с ещё не перемещённой версией фигуры
        if (field[coordinates[i][0]][coordinates[i][1] - 1] and !flag) {
            return true;
        }
    }
    return false;
};

bool figure::collision_uni(vector <array<short, 2>> changed_coordinates) {
    for (int i = 0; i < 4; i++) {
        if ((changed_coordinates[i][1] == 0) or (changed_coordinates[i][0] < 0) or (changed_coordinates[i][0] > 9)) return true;
    }

    for (int i = 0; i < 4; i++) {
        bool flag = find(coordinates, changed_coordinates[i]); //проверка, является ли столкновение столкновением с ещё не перемещённой версией фигуры
        if (field[changed_coordinates[i][0]][changed_coordinates[i][1]] and !flag) {
            return true;
        }
    }
    return false;
};

bool figure::physics(vector <array<short, 2>> coordinates, array <array<bool, 24>, 10>& field, short position, short figure, short y, short x) {
    bool flag{ false };
    while (!flag) {
        input_movement(coordinates, field, chrono::milliseconds(500)); //функция поворота\перемещения влево, вправо должна быть здесь
        flag = false;
        bool boom = collision_dwn();
        if (boom) {
            line_n_drop();
            flag = true;
        }
        if (!flag) {
            field[coordinates[0][0]][coordinates[0][1]] = false;
            field[coordinates[1][0]][coordinates[1][1]] = false;
            field[coordinates[2][0]][coordinates[2][1]] = false;
            field[coordinates[3][0]][coordinates[3][1]] = false;
            coordinates[0][1]--;
            coordinates[1][1]--;
            coordinates[2][1]--;
            coordinates[3][1]--;
            y--;
            field[coordinates[0][0]][coordinates[0][1]] = true;
            field[coordinates[1][0]][coordinates[1][1]] = true;
            field[coordinates[2][0]][coordinates[2][1]] = true;
            field[coordinates[3][0]][coordinates[3][1]] = true;
        }
        field_render();
        cout << figure << endl;
        //Проверка на столкновение, которое вызывает проигрыш
        if ((boom) && ((coordinates[0][1] > 19) || (coordinates[1][1] > 19) || (coordinates[2][1] > 19) || (coordinates[3][1] > 19))) {
            return 1;
        }
    }
    return 0;
}

void figure::input_movement(vector <array<short, 2>>& coordinates, array <array<bool, 24>, 10>& field, chrono::milliseconds time_for_move) {
    const auto start = chrono::steady_clock::now();
    while (true)
    {

        bool kbhit = _kbhit();
        if (kbhit) {
            int key = _getch();
            if (key == 224) {
                int key2 = _getch();
                vector <array<short, 2>> changed_coordinates{ {coordinates[0][0], coordinates[0][1]},
                                                                  {coordinates[1][0], coordinates[1][1]},
                                                                  {coordinates[2][0], coordinates[2][1]},
                                                                  {coordinates[3][0], coordinates[3][1]} };
                switch (key2)
                {
                    //стрелка влево
                case 75: {
                    for (int i = 0; i < 4; i++) changed_coordinates[i][0]--;
                    if (!collision_uni(changed_coordinates)) {
                        field[coordinates[0][0]][coordinates[0][1]] = false;
                        field[coordinates[1][0]][coordinates[1][1]] = false;
                        field[coordinates[2][0]][coordinates[2][1]] = false;
                        field[coordinates[3][0]][coordinates[3][1]] = false;
                        coordinates = changed_coordinates;
                        x--;
                    }
                    break;
                }
                       //стрелка вправо
                case 77: {
                    for (int i = 0; i < 4; i++) changed_coordinates[i][0]++;
                    if (!collision_uni(changed_coordinates)) {
                        field[coordinates[0][0]][coordinates[0][1]] = false;
                        field[coordinates[1][0]][coordinates[1][1]] = false;
                        field[coordinates[2][0]][coordinates[2][1]] = false;
                        field[coordinates[3][0]][coordinates[3][1]] = false;
                        coordinates = changed_coordinates;
                        x++;
                    }
                    break;
                }
                       //стрелка вверх
                case 72: {
                    position = (position + 1) % 4;
                    changed_coordinates = figure_position_example[figure_num][position];
                    for (int i = 0; i < 4; i++) {
                        changed_coordinates[i][0] += x;
                        changed_coordinates[i][1] += y;
                    }
                    if (!collision_uni(changed_coordinates)) {
                        field[coordinates[0][0]][coordinates[0][1]] = false;
                        field[coordinates[1][0]][coordinates[1][1]] = false;
                        field[coordinates[2][0]][coordinates[2][1]] = false;
                        field[coordinates[3][0]][coordinates[3][1]] = false;
                        coordinates = changed_coordinates;
                    }
                    break;
                }
                case 80: {
                    time_for_move = chrono::milliseconds(25);
                }
                default:
                    break;
                }
            }
        }
        const auto end = chrono::steady_clock::now();
        const chrono::duration<double> diff = end - start;
        if (diff > time_for_move) return; time_for_move = chrono::milliseconds(500);
    }
    return;
}