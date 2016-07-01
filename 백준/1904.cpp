#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int dp[1000001][2];

int main(void){
	int N;
	scanf("%d", &N);
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;

	for (int i = 3; i <= N; i++){
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 15746;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % 15746;
	}

	printf("%d", (dp[N][0] + dp[N][1]) % 15746);
}