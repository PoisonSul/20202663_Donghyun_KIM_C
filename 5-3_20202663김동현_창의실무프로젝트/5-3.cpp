#include <stdio.h>
#include <string.h>

void bubble(char* str, int count);  // �Լ� ����

int main() {
    char str[80];

    printf("���ڿ� �Է� : ");
    gets_s(str);
    bubble(str, strlen(str));
    printf("���ڿ��� ���� ������ ��� : %s\n", str);
}

void bubble(char* str, int count) {
    int nPass = 0;
    int nChange = 1;
    char cTemp;

    printf("\n[���� ���� �Լ� ����]\n");
    // (n-1)ȸ nPass �ݺ� ����
    while (nPass < count - 1 && nChange) {
        nChange = 0;
        for (int i = 0; i < count - nPass - 1; i++) {  // �ݺ� ���� i �������Ѿ� �մϴ�.
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