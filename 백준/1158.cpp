#include<stdio.h>

typedef struct people {
	int num;
	struct people * next;
	struct people * back;
}people;

int main(void) {
	int num;
	int index;
	int count;
	people man[5001];
	people * cur;

	scanf("%d %d", &num, &index);
	count = num;

	for (int i = 1; i <= num; i++) {
		man[i].num = i;
		man[i].next = &man[i + 1];
		man[i].back = &man[i - 1];
	}

	man[1].back = &man[num];
	man[num].next = &man[1];

	cur = &man[1];
	printf("<");
	while (count) {
		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}
		cur->next->back = cur->back;
		cur->back->next = cur->next;
		printf("%d", cur->num);
		cur = cur->next;
		count--;
		if (count) {
			printf(", ");
		}
	}
	printf(">");
}