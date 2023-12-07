#include <stdio.h>
void main() {
	int i = 0, j = 1, su = 1, dan;

	while (i <= 2) {
		su = 1;
		while (su <= 9) {
			j = 1;
			while (j <= 3) {
				dan = 3 * i + j;
					printf("%d + %d = %2d\t", dan, su, dan * su);
					j++;
			}
			su++;
			printf(" \n");
		}
		i++;
		printf(" \n");
	}
	i++;
	printf(" \n");

}