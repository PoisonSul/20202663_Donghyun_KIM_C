#include <stdio.h>

void main(void) {
    int month, days;
    printf("달을 입력하시오: ");
    scanf("%d", &month);

    if (month == 2)
        days = 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else
        days = 31;

    printf("%d월의 일수는 %d입니다.\n", month, days);
}