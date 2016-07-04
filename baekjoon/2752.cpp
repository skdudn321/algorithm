#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b) {
	if (*(int *)a > *(int *)b) {
		return 1;
	}
	else {
		return -1;
	}
}

int main(void) {
	int num[3];

	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	qsort(num, 3, sizeof(int), compare);

	printf("%d %d %d\n", num[0], num[1], num[2]);
}