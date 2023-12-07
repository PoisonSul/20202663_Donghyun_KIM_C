#include <stdio.h>

void main() {

	int x, y;
	char xy;

	printf("****result **** \n\n");
	printf("Input x xy y == ? ");
	scanf("%d %c %d", &x, &xy, &y);

	switch (xy) {
	case '*':
		printf("%d * %d = %d\n", x, y, x * y);
	case '/':
		printf("%d / %d = %d\n", x, y, x / y);
	case '+':
		printf("%d + %d = %d\n", x, y, x + y);
	case '-':
		printf("%d - %d = %d\n", x, y, x - y);
	}
}