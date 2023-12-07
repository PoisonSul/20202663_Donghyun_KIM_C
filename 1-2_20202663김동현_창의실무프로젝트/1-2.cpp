#include <stdio.h>

void main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // 이동한 후에 빈 공간에 양수는 0이 채워지고 음수는 1이 채워진다.
    switch (num >> 31) {
    case -1:
        printf("Number is negative\n");
        break;
    default:
        printf("Number is positive\n");
    }
}