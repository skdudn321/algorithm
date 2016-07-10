#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

double dp[1001][2001];

int main(void) {
	int T;
	scanf("%d", &T);
	dp[0][0] = 1;
	dp[1][1] = 0.25;
	dp[1][2] = 0.75;
	for (int i = 2; i <= 1000; i++) {
		for (int j = i; j <= i * 2; j++) {
			dp[i][j] = dp[i - 1][j - 1] * 0.25 + dp[i - 1][j - 2] * 0.75;
		}
	}
	for (int i = 1; i <= T; i++) {
		int N, M;
		scanf("%d %d", &N, &M);
		double ans = 0;
		for (int j = N; j <= N * 2; j++) {
			ans += dp[M][j];
		}
		printf("%.10lf\n", ans);
	}
}