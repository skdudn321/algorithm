#include<stdio.h>

int main(void){
	long long int num1, num2, sum;

	scanf("%lld %lld", &num1, &num2);

	if (num2 < num1){
		sum = num2;
		num2 = num1;
		num1 = sum;
	}

	sum = (num1 + num2) * (num2 - num1 + 1) / 2;

	printf("%lld", sum);
}