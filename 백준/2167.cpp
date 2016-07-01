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

int dp[301][301];

int main(void) {
	int N, M;
	
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &dp[i][j]);
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int T;
	scanf("%d", &T);

	int a, b, c, d;
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", dp[c][d] + dp[a - 1][b - 1] - dp[a - 1][d] - dp[c][b - 1]);
	}
}