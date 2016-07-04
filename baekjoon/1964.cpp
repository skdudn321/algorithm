#include<stdio.h>

int main(void){
	long long int N, sum;

	scanf("%lld", &N);

	sum = (N + 1 + 3 * (((N + 1) % 45678) * (N % 45678) / 2)) % 45678;

	printf("%lld", sum);
}