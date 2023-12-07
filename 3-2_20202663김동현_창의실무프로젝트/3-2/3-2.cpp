#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char ch1, ch2;
    int i;

    printf("여러 글자를 입력: ");
    gets_s(str);

    printf("기존 문자와 새로운 문자: ");
    scanf("%c %c", &ch1, &ch2);

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ch1) {
            str[i] = ch2;
        }
    }

    printf("변환된 결과 ==> %s\n", str);

    return 0;
}