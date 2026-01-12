#include "Header.h"
#include <string>
#include <vector>
using namespace std;

//создание поля
string** teb(int n, int m) {
	string** nums = new string * [m];
	for (int i = 0; i < m; i++) {
		nums[i] = new string[n];
	}
	return nums;
}

//Заполнение поля пустотой
void zapoln(string** table, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			table[i][j] = "  ";
		}
	}
}

//Вывод
void print(string** table, int n, int m, int count) {
	cout << "\n\tКол-во Собранных яблок: " << count << "\n\n";
	cout << " ~";
	for (int i = 0; i < m; i++) {
		cout << "~~";
	}
	cout << "~ " << endl;

	for (int i = 0; i < n; i++) {
		cout << "| ";
		for (int j = 0; j < m; j++) {
			cout << table[i][j];
		}
		cout << " |" << endl;
	}

	cout << " ~";
	for (int i = 0; i < m; i++) {
		cout << "~~";
	}
	cout << "~ " << endl;

}

//Наложение Змеи на поле
void overlay_snake(string** table, vector <snake> sn) {
	for (size_t i = 0; i < sn.size(); i++) {
		table[sn[i].x][sn[i].y] = sn[i].part;
	}
}

//наложение камней на поле
void overlay_stone(string** table, vector <stone> st) {
	for (size_t i = 0; i < st.size(); i++) {
		table[st[i].x][st[i].y] = st[i].s;
	}
}

//Обмен координат змеи(сам ход)
void obmen(vector <snake>& sn) {
	for (size_t i = sn.size() - 1; i > 0; i--) {
		sn[i].x = sn[i - 1].x;
		sn[i].y = sn[i - 1].y;
	}
}

//вызов шага + проверка на проигрыш
bool step(vector <snake>& sn, string** table, int* apple, int num, int n, int m, int& count) {
	const snake s = { sn[sn.size() - 1].x, sn[sn.size() - 1].y, " *" };
	switch (num) {
	case 2:
		if (sn[0].x + 1 < n) {
			sn[0].part = " v";
			if (table[sn[0].x + 1][sn[0].y] == " *" || table[sn[0].x + 1][sn[0].y] == " #") return false;
			if (table[sn[0].x + 1][sn[0].y] == " Q") {
				sn[0].x += 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].x -= 1;
				apples(apple, sn, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].x += 1;
			}
		}
		else return false;
		break;
	case 8:
		if (sn[0].x - 1 >= 0) {
			sn[0].part = " ^";
			if (table[sn[0].x - 1][sn[0].y] == " *" || table[sn[0].x - 1][sn[0].y] == " #") return false;
			if (table[sn[0].x - 1][sn[0].y] == " Q") {
				sn[0].x -= 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].x += 1;
				apples(apple, sn, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].x -= 1;
			}
		}
		else return false;
		break;
	case 4:
		if (sn[0].y - 1 >= 0) {
			sn[0].part = " <";
			if (table[sn[0].x][sn[0].y - 1] == " *" || table[sn[0].x][sn[0].y - 1] == " #") return false;
			if (table[sn[0].x][sn[0].y - 1] == " Q") {
				sn[0].y -= 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].y += 1;
				apples(apple, sn, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].y -= 1;
			}
		}
		else return false;
		break;

	case 6:
		if (sn[0].y + 1 < m) {
			sn[0].part = " >";
			if (table[sn[0].x][sn[0].y + 1] == " *" || table[sn[0].x][sn[0].y + 1] == " #") return false;
			if (table[sn[0].x][sn[0].y + 1] == " Q") {
				sn[0].y += 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].y -= 1;
				apples(apple, sn, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].y += 1;
			}
		}
		else return false;
		break;
	}
	return true;
}

//наложение яблока
void overlay_apple(string** table, int* apple) {
	table[apple[0]][apple[1]] = " Q";
}

//создание яблока
void apples(int* apple, vector <snake> sn, int n, int m) {
	bool f = true;
	int x, y;
	do {
		x = 0 + rand() % n;
		y = 0 + rand() % m;
		for (size_t i = 0; i < sn.size(); i++) {
			if (sn[i].x == x && sn[i].y == y ) {
				f = true;
				break;
			}
			else f = false;
		}
	} while (f);
	apple[0] = x;
	apple[1] = y;
}

//создание яблока для 3 уровня
void apples_two(int* apple, vector <snake> sn, vector <stone> st, int n, int m) {
	bool f = true;
	int x, y;
	do {
		x = 0 + rand() % n;
		y = 0 + rand() % m;
		for (size_t i = 0; i < sn.size(); i++) {
			if (sn[i].x == x && sn[i].y == y) {
				f = true;
				break;
			}
			else f = false;
		}
		for (size_t i = 0; i < st.size(); i++) {
			if (st[i].x == x && st[i].y == y) {
				f = true;
				break;
			}
			else f = false;
		}
	} while (f);
	apple[0] = x;
	apple[1] = y;
}

//создание камней
void ston(vector <stone>& st, vector <snake> sn, int n, int m) {
	bool f = true;
	int x, y, count = 0;
	do {
		x = 0 + rand() % n;
		y = 0 + rand() % m;
		for (size_t i = 0; i < sn.size(); i++) {
			if (sn[i].x == x && sn[i].y == y) {
				f = true;
				break;
			}
			else f = false;
		}
		if (f == false) {
			st.push_back({ x, y, " #" });
			count++; 
		}
	} while (f || count != 2);
}

//вызов шага + проверка на проигрыш для 3 уровня
bool step_two(vector <snake>& sn, vector <stone> st, string** table, int* apple, int num, int n, int m, int& count) {
	const snake s = { sn[sn.size() - 1].x, sn[sn.size() - 1].y, " *" };
	switch (num) {
	case 2:
		if (sn[0].x + 1 < n) {
			sn[0].part = " v";
			if (table[sn[0].x + 1][sn[0].y] == " *" || table[sn[0].x + 1][sn[0].y] == " #") return false;
			if (table[sn[0].x + 1][sn[0].y] == " Q") {
				sn[0].x += 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].x -= 1;
				apples_two(apple, sn, st, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].x += 1;
			}
		}
		else return false;
		break;
	case 8:
		if (sn[0].x - 1 >= 0) {
			sn[0].part = " ^";
			if (table[sn[0].x - 1][sn[0].y] == " *" || table[sn[0].x - 1][sn[0].y] == " #") return false;
			if (table[sn[0].x - 1][sn[0].y] == " Q") {
				sn[0].x -= 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].x += 1;
				apples_two(apple, sn, st, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].x -= 1;
			}
		}
		else return false;
		break;
	case 4:
		if (sn[0].y - 1 >= 0) {
			sn[0].part = " <";
			if (table[sn[0].x][sn[0].y - 1] == " *" || table[sn[0].x][sn[0].y - 1] == " #") return false;
			if (table[sn[0].x][sn[0].y - 1] == " Q") {
				sn[0].y -= 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].y += 1;
				apples_two(apple, sn, st, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].y -= 1;
			}
		}
		else return false;
		break;

	case 6:
		if (sn[0].y + 1 < m) {
			sn[0].part = " >";
			if (table[sn[0].x][sn[0].y + 1] == " *" || table[sn[0].x][sn[0].y + 1] == " #") return false;
			if (table[sn[0].x][sn[0].y + 1] == " Q") {
				sn[0].y += 1;
				sn.emplace_back(s);
				obmen(sn);
				sn[1].y -= 1;
				apples_two(apple, sn, st, n, m);
				count++;
			}
			else {
				obmen(sn);
				sn[0].y += 1;
			}
		}
		else return false;
		break;
	}
	return true;
}