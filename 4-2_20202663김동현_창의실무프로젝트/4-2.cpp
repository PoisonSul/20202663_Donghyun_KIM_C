//실습예제 4-2
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


void delete_middle(int* s, int** arr) {

	int nNewSize = *s - 1;
	int* temp;
	temp = (int*)malloc(sizeof(int) * nNewSize);
	int nNewIndex = 0;

	for (int i = 0; i <= *s; i++) {
		if (nNewIndex == *s / 2) {
			i++;
			temp[nNewIndex] = (*arr)[i];
		}
		else {
			temp[nNewIndex] = (*arr)[i];
		}
		nNewIndex;
	}

	free(*arr);

	*arr = temp;
	*s = nNewSize;
}

void main() {
	int N;
	scanf("%d", &N);

	int* Np;
	Np = (int*)malloc(sizeof(int) * N);


	for (int i = 0; i < N; i++)
		scanf("%d", &Np[i]);

	delete_middle(&N, &Np);

	for (int i = 0; i < N; i++)
		printf("%d", Np[i]);

	free(Np);
}