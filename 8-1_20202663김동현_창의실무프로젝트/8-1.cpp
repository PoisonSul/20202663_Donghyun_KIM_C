#include <stdio.h>
#include <Windows.h>
#include <time.h>

void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(char show)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

int main(void) {
	printf("Enter �Է� �� ���� : "); getchar();
	CursorView(0);
	srand((unsigned int)time(NULL));
	while(1){
		gotoxy((rand() % 300) / 2, rand() % 25);
		printf("*");
		Sleep(100);
	}
}