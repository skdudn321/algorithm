#include<stdio.h>

int main(void) {
	int num;
	int sum = 0;

	scanf("%d", &num);
	while (num > 0) {
		sum += (num % 2);
		num /= 2;
	}

	printf("%d", sum);
}