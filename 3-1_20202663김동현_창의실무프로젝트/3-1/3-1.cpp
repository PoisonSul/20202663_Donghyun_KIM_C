#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char in[50], out[50];
    int i, len;
    int diff = 'a' - 'A';

    printf("문자 입력: ");
    gets_s(in);

    len = strlen(in);
    for (i = 0; i < len; i++) {
        if (in[i] >= 'A' && in[i] <= 'Z') {
            out[i] = in[i] + diff;
        }
        else if (in[i] >= 'a' && in[i] <= 'z') {
            out[i] = in[i] - diff;
        }
        else {
            out[i] = in[i];
        }
    }
    out[i] = '\0';

    printf("변환된 문자: %s\n", out);

    return 0;
}