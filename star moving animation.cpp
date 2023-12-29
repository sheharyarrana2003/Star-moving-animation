#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void setclr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void top_bottom_r(int& a, int& b) {
	a = a + 1;
	b = b + 1;
}
void top_bottom_l(int& a, int& b) {
	a = a + 1;
	b = b - 1;
}
void bottom_top_r(int& a, int& b) {
	a = a - 1;
	b = b + 1;
}
void bottom_top_l (int& a, int& b) {
	a = a - 1;
	b = b - 1;
}
enum direction { T_B_L, T_B_R, B_T_R, B_T_L };
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// utility function to remove cursor
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);

	int speed = 80;
	srand(time(0));
	char ch = '*';
	direction dir = T_B_R;
	int h = 30, w = 120;
	int a = 0, b = 0;
	a = rand() % 30;
	b = rand() % 120;
	while (1) {
		if (dir == T_B_R && a == h) {
			setclr(1);
			dir = B_T_R;
		}
		if (dir == T_B_R && b == w) {
			setclr(2);
			dir = B_T_R;
		}

		if (dir == B_T_R && b == w) {
			setclr(3);
			dir = B_T_L;
		}
		if (dir == B_T_R && a == 0) {
			setclr(4);
			dir = T_B_R;
		}
		if (dir == T_B_L && a == h) {
			setclr(5);
			dir = B_T_L;
		}
		if (dir == T_B_L && b == 0) {
			setclr(6);
			dir = T_B_R;
		}
		if (dir == B_T_L && b == 0) {
			setclr(7);
			dir = B_T_R;
		}
		if (dir == B_T_L && a == 0) {
			setclr(8);
			dir = T_B_L;
		}
		gotoRowCol(a, b);
		cout << ch;
		Sleep(speed);
		system("cls");
		if (speed > 10) {
			speed -= 1;
		}
		switch (dir) {
		case T_B_L:
			top_bottom_l(a, b);
			break;
		case T_B_R:
			top_bottom_r(a, b);
			break;
		case B_T_L:
			bottom_top_l(a, b);
			break;
		case B_T_R:
			bottom_top_r(a, b);
			break;
		}
		if (_kbhit()) {
			setclr(15);
			char ch = _getch();
			if (ch == 27) {
				break;
				system("pasue");
			}

		}

	}
	return 0;
}
