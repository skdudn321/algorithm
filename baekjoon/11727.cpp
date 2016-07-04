#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int dp[1001][3];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[1][2] = 0;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 10007;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]) % 10007;
		dp[i][2] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]) % 10007;
	}

	printf("%d", (dp[N][0] + dp[N][1] + dp[N][2]) % 10007);
}