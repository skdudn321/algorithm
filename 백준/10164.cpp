#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int dp[16][16];

int main(void){
	dp[1][0] = 1;
	for (int i = 1; i <= 15; i++){
		for (int j = 1; j <= 15; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	if (K == 0){
		printf("%d", dp[N][M]);
		return 0;
	}
	else{
		int x = ((K - 1) / M) + 1, y = ((K - 1) % M) + 1;
		printf("%d", dp[x][y] * dp[N - x + 1][M - y + 1]);
	}
}