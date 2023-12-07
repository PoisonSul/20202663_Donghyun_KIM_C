#include <stdio.h>

int Add(int num1, int num2) {
    printf("\n[Add() 함수 영역]\n");
    return num1 + num2;
}

int Sub(int num1, int num2) {
    printf("\n[Sub() 함수 영역]\n");
    return num1 - num2;
}

int main() {
    int nResult = 0; // nResult를 초기화

    int (*fp)(int, int);
    printf("100과 200의 덧셈 연산과 뺄셈 연산\n");

    fp = Add;
    nResult = fp(100, 200); // Add 함수 호출 후 결과를 nResult에 할당
    printf("덧셈 연산 결과 : %d\n", nResult);

    fp = Sub;
    nResult = fp(100, 200); // Sub 함수 호출 후 결과를 nResult에 할당
    printf("뺄셈 연산 결과 : %d\n", nResult);
}