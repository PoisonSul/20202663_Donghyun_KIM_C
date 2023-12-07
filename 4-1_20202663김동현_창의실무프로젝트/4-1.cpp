#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void size_add(int* s, int** arr);  // �Լ� ���� �߰�

int main() {
    int* Np;
    int i = 0;
    int nSize = 3;
    Np = (int*)malloc(sizeof(int) * nSize);

    scanf("%d", &Np[0]);

    if (Np[0] != -1) {
        for (i = 1;; i++) {
            scanf("%d", &Np[i]);  // ����ڷκ��� �߰� ���� �Է�

            if (Np[i] == -1)
                break;

            if (i + 1 >= nSize)
                size_add(&nSize, &Np);
        }
        for (int j = 0; j < i; j++) {
            printf("%d ", Np[j]);
        }
    }

    free(Np);  // ���� �Ҵ� ����
    return 0;
}

void size_add(int* s, int** arr) {
    int nNewSize = *s + 3;
    int* temp = (int*)malloc(sizeof(int) * nNewSize);

    for (int i = 0; i < *s; i++)
        temp[i] = (*arr)[i];

    free(*arr);  // ���� �迭 ����
    *arr = temp;
    *s = nNewSize;
}