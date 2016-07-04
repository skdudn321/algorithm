#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int dp[1001][11];

int main(void){
	int N;
	scanf("%d", &N);
	for (int i = 9; i >= 0; i--){
		dp[0][i] = dp[0][i + 1] + 1;
	}

	for (int i = 1; i <= N - 1; i++){
		for (int j = 9; j >= 0; j--){
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % 10007;
		}
	}

	printf("%d", dp[N - 1][0]);
}