#include <stdio.h>

void main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // �̵��� �Ŀ� �� ������ ����� 0�� ä������ ������ 1�� ä������.
    switch (num >> 31) {
    case -1:
        printf("Number is negative\n");
        break;
    default:
        printf("Number is positive\n");
    }
}