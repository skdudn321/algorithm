#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

int coin[101];
int dp_table[10001];

int main(void){
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++){
		scanf("%d", &coin[i]);
	}

	dp_table[0] = 1;

	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= K; j++){
			if (coin[i] <= j){
				dp_table[j] = dp_table[j] + dp_table[j - coin[i]];
			}
			else{
				dp_table[j] = dp_table[j];
			}
		}
	}

	printf("%d", dp_table[K]);
}