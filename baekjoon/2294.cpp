#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int coin[101];
int dp_table[101][10001];

int main(void){
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= K; j++){
			dp_table[i][j] = 2000000000;
		}
	}

	for (int i = 1; i <= N; i++){
		scanf("%d", &coin[i]);
		if (coin[i] <= 10000){
			dp_table[i][coin[i]] = 1;
		}
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= K; j++){
			if (j < coin[i]){
				dp_table[i][j] = dp_table[i - 1][j];
			}
			else if(j > coin[i]){
				dp_table[i][j] = min(dp_table[i][j - coin[i]] + 1, dp_table[i - 1][j]);
			}
		}
	}
	if (dp_table[N][K] == 2000000000){
		printf("-1");
	}
	else{
		printf("%d", dp_table[N][K]);
	}
}