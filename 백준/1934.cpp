#include<stdio.h>

int main(void) {
	int start1, start2, a, b, temp;
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		start1 = a;
		start2 = b;
		if (a < b) {
			temp = b;
			b = a;
			a = temp;
		}
		while (a % b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}

		printf("%d\n", start1 * start2 / b);
	}

}