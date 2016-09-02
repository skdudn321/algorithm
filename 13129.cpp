#include<stdio.h>

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	A = A * C + B;
	for (int i = 1; i <= C; i++) {
		printf("%d ", A);
		A += B;
	}
}