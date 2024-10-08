//classes.cpp : �������� ������� game � figure
#pragma once

#include <getch_input.h>
#include <iostream>
#include <vector>
#include <array>
#include <chrono>
//#include "field_render.cpp"

using namespace std;

//void field_render(array <array<bool, 24>, 10> field, unsigned score);

class game;
class figure;

class figure
{
	//��������� ���������� �����
private: const vector<vector<vector<array<short, 2>>>> figure_position_example
{
	{ {{4, 0}, {4, 1}, {5, 0}, {5, 1}}, {{4, 0}, {4, 1}, {5, 0}, {5, 1}}, {{4, 0}, {4, 1}, {5, 0}, {5, 1}}, {{4, 0}, {4, 1}, {5, 0}, {5, 1}} },//O
	{ {{4, 3}, {4, 2}, {4, 1}, {4, 0}}, {{3, 1}, {4, 1}, {5, 1}, {6, 1}}, {{4, 3}, {4, 2}, {4, 1}, {4, 0}}, {{3, 1}, {4, 1}, {5, 1}, {6, 1}} },//I
	{ {{4, 0}, {4, 1}, {5, 1}, {5, 2}}, {{3, 2}, {4, 2}, {4, 1}, {5, 1}}, {{4, 0}, {4, 1}, {5, 1}, {5, 2}}, {{3, 2}, {4, 2}, {4, 1}, {5, 1}} },//Z
	{ {{4, 2}, {4, 1}, {5, 1}, {5, 0}}, {{3, 1}, {4, 1}, {4, 2}, {5, 2}}, {{4, 2}, {4, 1}, {5, 1}, {5, 0}}, {{4, 1}, {5, 1}, {5, 2}, {6, 2}} },//S
	{ {{4, 2}, {4, 1}, {4, 0}, {5, 0}}, {{3, 0}, {3, 1}, {4, 1}, {5, 1}}, {{4, 2}, {5, 2}, {5, 1}, {5, 0}}, {{3, 0}, {4, 0}, {5, 0}, {5, 1}} },//L
	{ {{4, 0}, {5, 0}, {5, 1}, {5, 2}}, {{3, 1}, {3, 0}, {4, 0}, {5, 0}}, {{4, 0}, {4, 1}, {4, 2}, {5, 2}}, {{3, 1}, {4, 1}, {5, 1}, {5, 0}} },//J
	{ {{3, 0}, {4, 0}, {5, 0}, {4, 1}}, {{4, 0}, {4, 1}, {4, 2}, {5, 1}}, {{3, 1}, {4, 1}, {5, 1}, {4, 0}}, {{4, 1}, {5, 0}, {5, 1}, {5, 2}} } //T
};
public:
	//����
	unsigned score;
	//������ �� ���������� ����
	array <array<bool, 24>, 10> field;
	//����� ������
	short figure_num;
	//"�������" ������ (������� ������)
	short position;
	//���������� ���� ����� ������
	vector <array<short, 2>> coordinates;
	//��������� ������ ������
	short y;
	//��������� ��������� ������ �� X
	short x;
private:
	//����� �������
	//void field_render(array <array<bool, 24>, 10>, unsigned);

	//��������� ����, ������ ����� ����� ���������� ��� �� ���� ���������. !!!!!! ������� ���������, �������� �� ���������� ���������.
	void field_render() {
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
		cout << "score: " << score << endl;
		return;
	}

	//�������� ������������ ������ � ������� �� ���� ��� �������� ����
	bool fall_collision() {
		for (int i = 0; i < 4; i++) {
			if (coordinates[i][1] == 0) return true;
		}

		for (int i = 0; i < 4; i++) {
			array<short, 2> array{ coordinates[i][0], coordinates[i][1] - 1 };
			bool flag = find(coordinates, array); //��������, �������� �� ������������ ������������� � ��� �� ������������ ������� ������
			if (field[coordinates[i][0]][coordinates[i][1] - 1] and !flag) {
				return true;
			}
		}
		return false;
	};

	//�������� �� ������������, �� ���������� �����������
	bool collision_uni(vector <array<short, 2>> changed_coordinates) {
		for (int i = 0; i < 4; i++) {
			if ((changed_coordinates[i][1] == 0) or (changed_coordinates[i][0] < 0) or (changed_coordinates[i][0] > 9)) return true;
		}

		for (int i = 0; i < 4; i++) {
			bool flag = find(coordinates, changed_coordinates[i]); //��������, �������� �� ������������ ������������� � ��� �� ������������ ������� ������
			if (field[changed_coordinates[i][0]][changed_coordinates[i][1]] and !flag) {
				return true;
			}
		}
		return false;
	};

	//���������������� �������� �� ��������� ��������� � ������
	inline bool find(vector <array<short, 2>> coordinates_func, array<short, 2> array) { //���������������� �������� �� ��������� ��������� � ������.
		for (int i = 0; i < 4; i++) {
			if (coordinates_func[i] == array) return true;
		}
		return false;
	}

	//��������, ��������� ����������� �������
	bool line_n_drop()
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

			score++;
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

	//������� �������.
	bool physics() {
		bool flag{ false };
		while (!flag) {
			movement(chrono::milliseconds(500)); //������� ��������\����������� �����, ������ ������ ���� �����
			flag = false;
			bool boom = fall_collision();
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
			//�������� �� ������������, ������� �������� ��������
			if ((boom) && ((coordinates[0][1] > 19) || (coordinates[1][1] > 19) || (coordinates[2][1] > 19) || (coordinates[3][1] > 19))) {
				return 1;
			}
		}
		return 0;
	}

	//������� ����������� ������
	void movement(chrono::milliseconds time_for_move) {
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
						//������� �����
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
						   //������� ������
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
						   //������� �����
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

public:
	//�����������
	figure(array <array<bool, 24>, 10> game_field, unsigned game_score, short input_figure_num, short input_position)
	{
		field = game_field;
		score = game_score;
		figure_num = input_figure_num;
		position = input_position;

		coordinates = figure_position_example[figure_num][position];

		y = 20;
		x = 0;

		for (int i = 0; i < y; i++) {
			coordinates[0][1]++;
			coordinates[1][1]++;
			coordinates[2][1]++;
			coordinates[3][1]++;
		}
		physics();
	}
};

class game
{
private:
	//����

	unsigned score;
	//������ �� ���������� ����
	array <array<bool, 24>, 10> field;

public:
	//�������������
	game()
	{
		score = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 24; j++) {
				field[i][j] = false;
			}
		}
		while (true) //���� ��� ������������, ��������������� � ���, ��� ������ ������ �� ������� ������� ����, ������� �����.
		{
			figure figure(field, score, rand_int_input(0, 6), rand_int_input(0, 3));
			score++;
			cout << "score = " << score << endl; //!!!!!!!!���� ������� ������� �����, ���� ������ ���
			field = figure.field;
			score = figure.score;
		}
		cout << "Game over :(\n";
	}
};



