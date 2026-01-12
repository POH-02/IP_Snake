#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct snake {
	int x;
	int y;
	string part;
};

struct stone {
	int x;
	int y;
	string s;
};

string** teb(int n, int m);
void zapoln(string** table, int n, int m);
void print(string** table, int n, int m, int count);
void overlay_snake(string** table, vector <snake> sn);
void overlay_apple(string** table, int* apple);
void overlay_stone(string** table, vector <stone> st);
void apples(int* apple, vector <snake> sn, int n, int m);
void apples_two(int* apple, vector <snake> sn, vector <stone> st, int n, int m);
void ston(vector <stone>& st, vector <snake> sn, int n, int m);
bool step(vector <snake>& sn, string** table, int* apple, int num, int n, int m, int& count);
bool step_two(vector <snake>& sn, vector <stone> st, string** table, int* apple, int num, int n, int m, int& count);
void obmen(vector <snake>& sn);

void start_game();
int menu();
void level_one(int n, int m);
void level_two(int n, int m);
void level_tree(int n, int m);

#endif