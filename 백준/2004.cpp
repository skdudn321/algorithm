#include<stdio.h>

int num1, num2;
long long int sum5 = 0, sum2 = 0;

long long int cal1(int index);
long long int cal2(int index);

int main(void){
	scanf("%d %d", &num1, &num2);

	if (num1 - num2 < num2){
		num2 = num1 - num2;
	}

	sum2 += cal1(2);
	sum5 += cal1(5);

	sum2 += cal2(2);
	sum5 += cal2(5);

	if (sum2 > sum5){
		printf("%lld", sum5);
	}
	else{
		printf("%lld", sum2);
	}
}

long long int cal1(int index){
	long long int rvalue = 0;
	int re_num = num1 - num2;
	long long int temp = index;

	while (temp <= num1){
		rvalue += num1 / temp;
		rvalue -= re_num / temp;
		temp *= index;
	}

	return rvalue;
}
long long int cal2(int index){
	long long int rvalue = 0;
	long long int temp = index;

	while (temp <= num2){
		rvalue -= num2 / temp;
		temp *= index;
	}

	return rvalue;
}