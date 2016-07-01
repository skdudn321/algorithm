#include<stdio.h>

int main(void) {
	int N;
	int i, j;

	scanf("%d", &N);

	for (j = 0; j < N; j++) {
		for (i = 0; i < j; i++) {
			printf(" ");
		}
		for (i = 2 * (N - j) - 1; i > 0; i--) {
			printf("*");
		}
		printf("\n");
	}
	for (j = 1; j < N; j++) {
		for (i = N - j - 1; i > 0; i--) {
			printf(" ");
		}
		for (i = 0; i < 2 * j + 1; i++) {
			printf("*");
		}
		printf("\n");
	}
}