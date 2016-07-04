#include<stdio.h>

int podo[10001];
int dp_table[10001];

int main(void){
	int N, temp1;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		scanf("%d", &podo[i]);
	}

	dp_table[1] = podo[1];
	dp_table[2] = dp_table[1] + podo[2];

	for (int i = 3; i <= N; i++){
		temp1 = dp_table[i - 1] > dp_table[i - 2] + podo[i] ? dp_table[i - 1] : dp_table[i - 2] + podo[i];
		dp_table[i] = dp_table[i - 3] + podo[i] + podo[i - 1] > temp1 ? dp_table[i - 3] + podo[i] + podo[i - 1] : temp1;
	}

	printf("%d", dp_table[N]);
}