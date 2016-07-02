#include<stdio.h>

int main(void) {
	int a, b;
	char temp = 0;

	while ((temp = getchar()) != EOF) {
		ungetc(temp, stdin);
		scanf("%d %d\n", &a, &b);
		printf("%d\n", a + b);
	}
}