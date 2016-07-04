#include<stdio.h>
#include<stdlib.h>

typedef struct ha {
	int num;
	int index;
}ha;

int compare(const void * a, const void * b);

int main(void) {
	int i;
	ha num[9];

	for (i = 0; i < 9; i++) {
		scanf("%d", &num[i].num);
		num[i].index = i + 1;
	}

	qsort(num, 9, sizeof(ha), compare);

	printf("%d\n%d", num[0].num, num[0].index);
}

int compare(const void * a, const void * b) {
	if ((*(ha*)a).num > (*(ha*)b).num) {
		return -1;
	}
	else if ((*(ha*)a).num < (*(ha*)b).num) {
		return 1;
	}
	else {
		return 0;
	}
}