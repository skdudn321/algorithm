#include<stdio.h>

int main(void) {
	int A, B, T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &A, &B);
		while (A != B) {
			if (B > A) {
				int temp = A;
				A = B;
				B = temp;
			}
			A /= 2;
		}
		printf("%d\n", 10 * A);
	}
}