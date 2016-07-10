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

typedef pair<int, int> ii;

int table[101][101];
ii dp[101][101];

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= j; k++) {
				scanf("%d", &table[j][k]);
				dp[j][k] = ii(0, 0);
			}
		}
		dp[1][1] = ii(table[1][1], 1);
		for (int j = 2; j <= N; j++) {
			dp[j][1] = ii(dp[j - 1][1].first + table[j][1], dp[j - 1][1].second);
			dp[j][j] = ii(dp[j - 1][j - 1].first + table[j][j], dp[j - 1][j - 1].second);
			for (int k = 2; k <= N - 1; k++) {
				if (dp[j - 1][k].first == dp[j - 1][k - 1].first) {
					dp[j][k] = ii(dp[j - 1][k].first + table[j][k], dp[j - 1][k].second + dp[j - 1][k - 1].second);
				}
				else {
					dp[j][k] = max(dp[j - 1][k], dp[j - 1][k - 1]);
					dp[j][k].first += table[j][k];
				}
			}
		}
		int big = 0;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			big = max(big, dp[N][i].first);
		}
		for (int i = 1; i <= N; i++) {
			if (dp[N][i].first == big) {
				ans += dp[N][i].second;
			}
		}
		printf("%d\n", ans);
	}
}