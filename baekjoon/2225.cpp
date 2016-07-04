#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int dp[201][201];

int main(void){
	int N, K;

	scanf("%d %d", &N, &K);

	dp[0][0] = 1;

	for (int i = 1; i <= K; i++){
		for (int j = 0; j <= N; j++){
			for (int k = 0; k <= j; k++){
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000000;
			}
		}
	}

	printf("%d", dp[K][N]);
}