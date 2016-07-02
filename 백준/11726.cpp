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

int dp[1002][2];

int main(void) {
	int N;

	scanf("%d", &N);

	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][0] = 1;
	dp[2][1] = 1;

	for (int i = 3; i <= N + 1; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 10007;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % 10007;
	}

	printf("%d", (dp[N][0] + dp[N][1]) % 10007);
}