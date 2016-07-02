#include<stdio.h>

int main(void) {
	int a, b;
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d\n", &a, &b);
		printf("Case #%d: %d\n", i + 1, a + b);
	}
}