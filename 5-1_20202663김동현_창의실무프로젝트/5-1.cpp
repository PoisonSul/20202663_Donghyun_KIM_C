#include <stdio.h>

int Add(int num1, int num2) {
    printf("\n[Add() �Լ� ����]\n");
    return num1 + num2;
}

int Sub(int num1, int num2) {
    printf("\n[Sub() �Լ� ����]\n");
    return num1 - num2;
}

int main() {
    int nResult = 0; // nResult�� �ʱ�ȭ

    int (*fp)(int, int);
    printf("100�� 200�� ���� ����� ���� ����\n");

    fp = Add;
    nResult = fp(100, 200); // Add �Լ� ȣ�� �� ����� nResult�� �Ҵ�
    printf("���� ���� ��� : %d\n", nResult);

    fp = Sub;
    nResult = fp(100, 200); // Sub �Լ� ȣ�� �� ����� nResult�� �Ҵ�
    printf("���� ���� ��� : %d\n", nResult);
}