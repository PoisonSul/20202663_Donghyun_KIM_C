#pragma once
#include "Blocks.h"
#include "Controller.h"

//����
typedef enum Color {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
}COLOR;

int static level;

//�ι�° ���� Scene
void InGameFrame();
//���ӿ��� ��µ� ���� ��� �̸�����
void ShowNextBlock();
//���ӿ��� ��µ� ���� ��� �̸����� ����.
void DeleteNextBlock();
//�̸� ������ ����� �迭�� �����߽��ϴ�.
int NextBlock[6][6]; //nextshape
int static Rotation = 0;

void EndGameFrame();
void GameTitle();

/**
* Controller.c �ҽ������� tetirs_process()�޼��忡��
* ��Ʈ���� ���� �� ���� ����� ��� "addBlock(shape, rotate)">"�ǰ�,
* ��ĭ �������� ���� ��µ� ����� ����<deleteBlock()> ��
* y�� ������ ���·� (������ ����) ���� ��� �ٽ� ���!<addBlock(shape, rotate)
* ����� ���, ���� �ϴ� �Լ��Դϴ�.
*/
void addBlock(int shape, int rotate);
void deleteBlock();

//���� ����, 0�� 1�� ����, 1 = ��, 0 = �� ����, �ڼ��ϰԴ� blockFixed()�޼��� �ּ� ����
void createBoards();
int board[BoardHeight][BoardWidth];
void printBoards();

//��Ͽ� �÷��� �ֱ� ���ؤ� textcolor ����
void textcolor(int color_number);