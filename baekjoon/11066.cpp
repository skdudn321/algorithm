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

int ans;

int table[501];
ii dp[501][501];

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dp[j][k] = ii(2000000000, 0);
			}
		}
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[j]);
			dp[1][j] = ii(0, table[j]);
		}

		for (int j = 2; j <= N; j++) {
			for (int k = 1; k <= N - j + 1; k++) {
				for (int w = 1; w < j; w++) {
					dp[j][k] = min(ii(dp[j][k]), ii(dp[w][k].first + dp[j - w][k + w].first + dp[w][k].second + dp[j - w][k + w].second, dp[w][k].second + dp[j - w][k + w].second));
				}
			}
		}

		printf("%d\n", dp[N][1].first);
	}
}