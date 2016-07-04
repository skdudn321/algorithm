#include<stdio.h>
#include<stdlib.h>

float exp[100];

int compare(const void * a, const void * b);

int main(void) {
	int N, M, K;
	int temp;
	float t;
	int i, j;
	float sum = 0;

	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d %f", &temp, &t);
			if (exp[temp] < t) {
				exp[temp] = t;
			}
		}
	}

	qsort(exp + 1, N, sizeof(float), compare);

	for (i = 1; i <= K; i++) {
		sum += exp[i];
	}

	printf("%.1f", sum);
}

int compare(const void * a, const void * b) {
	if (*(float *)a > *(float *)b) {
		return -1;
	}
	else if (*(float *)a < *(float *)b) {
		return 1;
	}
	else {
		return 0;
	}
}