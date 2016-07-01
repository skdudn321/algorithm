#include<stdio.h>

int main(void) {
	int num1, num2, temp, su = 1, su2;
	int i;

	scanf("%d %d", &num1, &num2);
	
	if (num1 > num2) {
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	for (i = 2; i <= num1; i++) {
		if (num1 % i == 0) {
			if (num2 % i == 0) {
				su = i;
			}
		}
	}

	su2 = (num1 / su) * num2;

	printf("%d\n%d", su, su2);
}