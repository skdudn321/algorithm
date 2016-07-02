#include<stdio.h>

int jail[101];

int main(void) {
	int N, i, j, T;

	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			if (j % i == 0) {
				jail[j] = (jail[j] + 1) % 2;
			}
		}
	}

	for (i = 2; i <= 100; i++) {
		jail[i] += jail[i - 1];
	}

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d\n", jail[N]);
	}
}