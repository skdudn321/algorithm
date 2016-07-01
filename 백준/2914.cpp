#include<stdio.h>

int main(void){
	int N;
	int temp;
	int sum = 0;

	scanf("%d %d", &N, &temp);

	printf("%d", N * (temp - 1) + 1);
}
