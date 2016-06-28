#include<stdio.h>

int main(void) {
	int first1, first2;
	int num1;
	int num2;
	int temp;
	int i = 0;

	scanf("%d", &num2);

	num1 = num2 / 10;
	num2 %= 10;

	first1 = num1;
	first2 = num2;

	do {
		temp = (num1 + num2) % 10;
		num1 = num2;
		num2 = temp;
		i++;
	} while (first1 != num1 || first2 != num2);

	printf("%d", i);
}