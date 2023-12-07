#include <stdio.h>
#include <string.h>

void bubble(char* str, int count);  // 함수 선언

int main() {
    char str[80];

    printf("문자열 입력 : ");
    gets_s(str);
    bubble(str, strlen(str));
    printf("문자열을 버블 정렬한 결과 : %s\n", str);
}

void bubble(char* str, int count) {
    int nPass = 0;
    int nChange = 1;
    char cTemp;

    printf("\n[버블 정렬 함수 영역]\n");
    // (n-1)회 nPass 반복 수행
    while (nPass < count - 1 && nChange) {
        nChange = 0;
        for (int i = 0; i < count - nPass - 1; i++) {  // 반복 변수 i 증가시켜야 합니다.
            if (str[i] > str[i + 1]) {
                nChange = 1;
                cTemp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = cTemp;
            }
        }
        nPass++;
    }
}