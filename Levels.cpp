#include "Header.h"
#include <string>
#include <vector>
using namespace std;

int menu() {
	cout << "1 - уровеннь I" << endl;
	cout << "2 - уровеннь II" << endl;
	cout << "3 - уровеннь III" << endl;
	cout << "0 - Выйти" << endl;
	cout << "Ваш выбор: ";
	int num;
	cin >> num;
	return num;
}

void start_game() {
	cout << "Добро пожаловать." << endl;
	cout << "Это игра \"Змейка\" с 3 разными уровнями." << endl;
	cout << "Начнем же.\nВыбери уровень\n";
	int num, n, m;
	num = menu();
	while (num != 0){
		switch (num) {
		case 1:
			cout << "\n\tLEVEL I\n";
			n = 5;
			m = 5;
			cout << endl << "Твоя задача собрать 5 яблок" << endl;
			level_one(n, m);
			cout << "Еще? \n";
			num = menu();
			break;
		case 2:
			cout << "\n\tLEVEL II\n";
			n = 7;
			m = 7;
			cout << endl << "Твоя задача собрать 7 яблок" << endl;
			level_two(n, m);
			cout << "Еще? \n";
			num = menu();
			break;
		case 3:
			cout << "\n\tLEVEL III\n";
			n = 8;
			m = 8;
			cout << endl << "Твоя задача собрать 10 яблок" << endl;
			cout << "Опасайся камней" << endl;
			level_tree(n, m);
			cout << "Еще? \n";
			num = menu();
			break;
		case 0:
			cout << "Всего доброго!";
			break;
		default:
			cout << "\nНеверный ввод.\n Попробуй еще раз: ";
			num = menu();
			break;
		}
	}
}

void level_one(int n, int m) {
	vector <snake> sn;
	string** table = teb(n, m);
	int apple[2];
	int count = 0;
	sn.push_back({ 0, 0 , " >" });
	zapoln(table, n, m);
	apples(apple, sn, n, m);
	overlay_snake(table, sn);
	overlay_apple(table, apple);
	print(table, n, m, count);
	int num;
	cout << "Введите направление (8, 2, 4 или 6): ";
	cin >> num;
	while (num != 2 && num != 4 && num != 6 && num != 8 && num != 0) {
		cout << "Неверный ввод. Попробуй еще раз: ";
		cin >> num;
	}
	while (count != 5 && num != 0 && step(sn, table, apple, num, n, m, count)) {
		zapoln(table, n, m);
		overlay_apple(table, apple);
		overlay_snake(table, sn);
		print(table, n, m, count);
		cout << "Введите направление (8, 2, 4 или 6): ";
		cin >> num;
		while (num != 2 && num != 4 && num != 6 && num != 8) {
			cout << "Неверный ввод. Попробуй еще раз: ";
			cin >> num;
		}
	}
	if (count == 5) cout << "Ты прошел уровень. " << endl;
	else cout << "Ты проиграл. " << endl;
}

void level_two(int n, int m) {
	vector <snake> sn;
	string** table = teb(n, m);
	int apple[2];
	int count = 0;

	//изначальная змея
	sn.push_back({ 2, 1 , " ^" });
	sn.push_back({ 3, 1 , " *" });
	sn.push_back({ 3, 2 , " *" });
	sn.push_back({ 3, 3 , " *" });
	sn.push_back({ 3, 4 , " *" });
	sn.push_back({ 4, 4 , " *" });

	zapoln(table, n, m);
	apples(apple, sn, n, m);
	overlay_snake(table, sn);
	overlay_apple(table, apple);
	print(table, n, m, count);
	int num;
	cout << "Введите направление (8, 2, 4 или 6): ";
	cin >> num;
	while (num != 2 && num != 4 && num != 6 && num != 8 && num != 0) {
		cout << "Неверный ввод.\n Попробуй еще раз: ";
		cin >> num;
	}
	while (count != 7 && num != 0 && step(sn, table, apple, num, n, m, count)) {
		zapoln(table, n, m);
		overlay_apple(table, apple);
		overlay_snake(table, sn);
		print(table, n, m, count);
		cout << "Введите направление (8, 2, 4 или 6): ";
		cin >> num;
		while (num != 2 && num != 4 && num != 6 && num != 8) {
			cout << "Неверный ввод.\n Попробуй еще раз: ";
			cin >> num;
		}
	}
	if (num == 0) cout << "Всего доброго" << endl;
	else if (count == 7) cout << "Ты прошел уровень. " << endl;
	else cout << "Ты проиграл. " << endl;
}

void level_tree(int n, int m) {
	vector <stone> st;
	vector <snake> sn;
	string** table = teb(n, m);
	int apple[2];
	int count = 0;

	//изначальная змея
	sn.push_back({ 2, 1 , " ^" });
	sn.push_back({ 3, 1 , " *" });
	sn.push_back({ 3, 2 , " *" });
	sn.push_back({ 3, 3 , " *" });
	sn.push_back({ 3, 4 , " *" });
	sn.push_back({ 4, 4 , " *" });
	sn.push_back({ 4, 5 , " *" });
	sn.push_back({ 4, 6 , " *" });
	sn.push_back({ 5, 6 , " *" });
	sn.push_back({ 6, 6 , " *" });


	zapoln(table, n, m);
	ston(st, sn, n, m);
	apples_two(apple, sn, st, n, m);
	overlay_snake(table, sn);
	overlay_stone(table, st);
	overlay_apple(table, apple);
	print(table, n, m, count);
	int num;
	cout << "Введите направление (8, 2, 4 или 6): ";
	cin >> num;
	while (num != 2 && num != 4 && num != 6 && num != 8 && num != 0) {
		cout << "   Неверный ввод.\n  Попробуй еще раз: ";
		cin >> num;
	}
	while (count != 10 && num != 0 && step_two(sn, st, table, apple, num, n, m, count)) {
		zapoln(table, n, m);
		overlay_apple(table, apple);
		overlay_stone(table, st);
		overlay_snake(table, sn);
		print(table, n, m, count);
		cout << "Введите направление (8, 2, 4 или 6): ";
		cin >> num;
		while (num != 2 && num != 4 && num != 6 && num != 8) {
			cout << "Неверный ввод.\n Попробуй еще раз: ";
			cin >> num;
		}
	}
	if (count == 10) cout << "Ты прошел уровень. " << endl;
	else cout << "Ты проиграл. " << endl;
}