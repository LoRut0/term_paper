#pragma once
#include <iostream>
#include <array>

using namespace std;

//��������� ����, ������ ����� ����� ���������� ��� �� ���� ���������. !!!!!! ������� ���������, �������� �� ���������� ���������.
void field_render(array <array<bool, 24>, 10> field, unsigned score) {
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
    return;
}