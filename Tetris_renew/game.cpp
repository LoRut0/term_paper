//game.cpp : описание класса game, который запускает figure

#include "classes.h"
#include "figure.cpp"

game::game()
{
    score = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 24; j++) {
            field[i][j] = false;
        }
    }

    while (true) //пока нет столкновения, результирующего в том, что фигура уходит за верхнюю границу поля, спавним новую.
    {
        figure figure(rand_int_input(0, 6), rand_int_input(0, 3));
        score++;
        cout << "score = " << score << endl; //!!!!!!!!Надо сделать систему очков, пока только так
    }
    cout << "Game over :(\n";
}

bool game::line_n_drop()
{
    bool flag = false;
    for (int y = 19; y >= 0; y--) {
        bool line = true;
        for (int x = 0; x < 10; x++) {
            if (!field[x][y]) {
                line = false;
                break;
            }
        }
        if (!line) continue; flag = true;
        short highest_y(0);
        for (int y = 19; y >= 0; y--) {
            for (int x = 0; x < 10; x++) {
                if (field[x][y]) {
                    highest_y = y;
                    break;
                }
            }
            if (highest_y > 0) break;
        }

        for (int x = 0; x < 10; x++) field[x][y] = false;

        for (int y_more = y; y_more < highest_y; y_more++) {
            for (int x = 0; x < 10; x++) {
                field[x][y_more] = field[x][y_more + 1];
                field[x][y_more + 1] = false;
                field_render();
            }
        }
    }
    if (flag) return 1;
    return 0;
}

int game::field_render() {
    system("cls");
    cout << "+==========+" << endl;
    for (int row = 19; row >= 0; row--) {
        cout << '|';
        for (int column = 0; column < 10; column++) {
            (field[column][row]) ? cout << '*' : cout << ' ';
        }
        cout << '|' << endl;
    }
    cout << "+==========+" << endl;
    return 0;
}