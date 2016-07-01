#include<stdio.h>

long long int dp_table[100];

int main(void){
	int N;
	scanf("%d", &N);

	dp_table[1] = 1;
	dp_table[2] = 1;

	for (int i = 3; i <= N; i++){
		dp_table[i] = dp_table[i - 1] + dp_table[i - 2];
	}

	printf("%lld", dp_table[N]);
}