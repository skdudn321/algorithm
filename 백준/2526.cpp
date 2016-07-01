#include<stdio.h>

int check[1001];

int main(void){
	int N, P, temp;
	int count = 1;

	scanf("%d %d", &N, &P);

	check[N] = count++;
	temp = (N * N) % P;
	while (check[temp] == 0){
		check[temp] = count++;
		temp = (temp * N) % P;
	}

	printf("%d", count - check[temp]);
}