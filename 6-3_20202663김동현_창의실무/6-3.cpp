#include<stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
	struct student* next;
};

void main(void) {
	struct student s1 = { 20231111, "Kim", 4.3, NULL };
	struct student s2 = { 20232222, "Park", 4.3, NULL };
	struct student* first = NULL;
	struct student* current = NULL;

	first = &s1;
	s1.next = &s2;
	s2.next = NULL;

	current = first;
	while (current != NULL) {
		printf("학생의 번호 : %d,\t 이름: %s,\t 성적: %.2f\n",
			current->number, current->name, current->grade);
		current = current->next;
	}



}