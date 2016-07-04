#include<stdio.h>
#include<stdlib.h>

int length[2000000];

int compare(const void * a, const void * b) {
	if (*(int *)a > *(int *)b) {
		return -1;
	}
	else if(*(int *)a < *(int *)b){
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	int N;
	int i;
	int max = -1;

	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &length[i]);
	}
	qsort(length, N, sizeof(int), compare);

	for (i = 0; i < N - 2; i++) {
		if (length[i] < length[i + 1] + length[i + 2]) {
			max = length[i] + length[i + 1] + length[i + 2];
			break;
		}
	}

	printf("%d", max);

	return 0;
}