#include <stdio.h>
void main(void) {

	int i = 1, s = 0;


	while (i <= 50) {

		s += i;
		i++;

	}
	printf("Sum from 1 to 50 = %d\n", s);

}