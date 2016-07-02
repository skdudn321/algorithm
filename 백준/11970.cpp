#include<stdio.h>

int num[101];

int main(void) {
	int a, b, c, d, sum = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	for (int i = a; i < b; i++) {
		num[i] = 1;
	}
	for (int i = c; i < d; i++) {
		num[i] = 1;
	}

	for (int i = 0; i <= 100; i++) {
		if (num[i]) {
			sum++;
		}
	}
	printf("%d", sum);
}