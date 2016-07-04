#include<stdio.h>

int main(void) {
	int a, b;

	while (true) {
		scanf("%d %d\n", &a, &b);
		if (a == 0 && b == 0) {
			return 0;
		}
		printf("%d\n", a + b);
	}
}