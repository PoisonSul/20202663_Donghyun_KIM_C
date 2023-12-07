#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define FALSE 0
#define TRUE 1

//����
enum {
BLACK,					//0
DARK_BLUE,			//1
DARK_GREEN,		//2
DARK_SKYBLUE,		//3
DARK_RED,				//4
DARK_YELLOW,		//5	
GRAY,						//6
DARK_GRAY,			//7
BLUE,						//8
GREEN,					//9
SKYBLUE,				//10
RED,						//11
VIOLET,					//12
YELLOW,					//13
WHITE,						//14
};

//�ܼ� �ؽ�Ʈ ���� �������ִ� �Լ�
void SetColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}


//Ŀ�� On / Off
void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView() {
	//Consoleâ�� ���� ũ��� ���� ũ�⸦ ����
	system("mode con:cols=100 lines=25");
		//Consoleâ�� ����â ǥ��
	system("title â�ǽǹ�������Ʈ ���� ���� ����");
	//Ŀ�� �Ⱥ��̰�
	CursorView(FALSE);
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {
	if (_kbhit() != 0) return _getch();
	return FALSE;
}

void DrawDino(int dinoY) {
	SetColor(SKYBLUE);
	GotoXY(0, dinoY);
	static int legFlag = TRUE;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (legFlag)
	{
		printf(" $$$   $$$\n");
		printf("$$$      $$$\n");
		legFlag = false;
	}
	else
	{
		printf(" $$$      $$$\n");
		printf("   $$$   $$$\n");
		legFlag = true;
	}
}

void DrawTree(int treeX)
{
	SetColor(GREEN);
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf("$$$$");
	SetColor(DARK_YELLOW);
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$  ");

}


//�浹 ������ ���ӿ��� �׷���
void DrawGameOver(const int score) {
	//ȭ���� û����
	//cls : Clean Screen�� ����.
	system("cls");
	SetColor(YELLOW);
	int x = 16, y = 8;
	GotoXY(x, y);

	printf("=================================");
	GotoXY(x, y + 1);
	printf("==========G A M E O V E R==========");
	GotoXY(x, y + 2);
	printf("=================================");
	GotoXY(x, y + 5);
	printf("SCORE : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");

}


	//�浹������ true, �ƴϸ� false           
	int IsCollision(const int treeX, const int dinoY) {
		//Ʈ���� x�� ������ ��ü�ʿ� ������,
		//������ ���̰� ������� �ʴٸ� �浹�� ó��
		GotoXY(0, 0);
		printf("treeX : %d, dinoY : %d", treeX, dinoY);  //�̷������� ������ X, Y�� ã���ϴ�.
		if (treeX <= 8 && treeX >= 4 && dinoY > 8) return TRUE;

		return FALSE;
	}
	
	int main() {
		SetConsoleView();

		while (TRUE) {
			//���� ���۽� �ʱ�ȭ
			int isJumping = FALSE;
			int isBottom = TRUE;
			const int gravity = 3;

			int dinoY = DINO_BOTTOM_Y;
			int treeX = TREE_BOTTOM_X;

			int score = 0;
			clock_t start, curr; //���� ���� �ʱ�ȭ
			start = clock();     // ���۽ð� �ʱ�ȭ

			while (TRUE) {
				if (IsCollision(treeX, dinoY)) break;

				//SpaceŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
				// Space Key ASCII :: 32
				if (GetKeyDown() == ' ' && isBottom) {
					isJumping = TRUE;
					isBottom = FALSE;
				}

				//�������̶�� Y�� ����, ������ �������� Y�� ����
				if (isJumping) dinoY -= gravity;
				else dinoY += gravity;

				//Y�� ����ؼ� �����ϤѤ��� �������� �ٴ��� ����.
				if (dinoY >= DINO_BOTTOM_Y) {
					dinoY = DINO_BOTTOM_Y;
					isBottom = TRUE;
				}

				//������ �������� (x����) �������ϰ�
				//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ
				treeX -= 2;
				if (treeX <= 0) treeX = TREE_BOTTOM_X;

				//������ ������ ������ ������ ���� ��Ȳ
				if (dinoY <= 3) isJumping = FALSE;

				DrawDino(dinoY); // draw dino
				DrawTree(treeX);  // draw Tree

				curr = clock(); //����ð� �޾ƿ���
				if (((curr - start) / CLOCKS_PER_SEC) >= 1) {			//1�ʰ� �Ѿ������
					score++;																//���ھ� UP
					start = clock();														//���۽ð� �ʱ�ȭ
				}
				Sleep(30);																	//Game Speed ����
				system("cls");															// clear

				SetColor(WHITE);

				//��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� ��������++
				GotoXY(22, 0); //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
				printf("Score : %d ", score);  //���� �������

				GotoXY(2, 2);
				printf("���� : Space Key");
			}
				//���� ���� �޴�
				DrawGameOver(score);
			}
			return FALSE;
		}
