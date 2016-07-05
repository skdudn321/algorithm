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

int ans;
int table[101][101];
int dp[101][101];

int main(void) {
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= j; k++) {
				scanf("%d", &table[j][k]);
			}
		}
		dp[1][1] = table[1][1];
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= j; k++) {
				if (k == 1) {
					dp[j][k] = dp[j - 1][k] + table[j][k];
				}
				else if (k == j) {
					dp[j][k] = dp[j - 1][k - 1] + table[j][k];
				}
				else {
					dp[j][k] = max(dp[j - 1][k], dp[j - 1][k - 1]) + table[j][k];
				}
			}
		}
		int ans = 0;
		for (int j = 1; j <= N; j++) {
			ans = max(ans, dp[N][j]);
		}
		printf("%d\n", ans);
	}
}