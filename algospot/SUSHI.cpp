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
int dp[401];
int cost[21];
int want[21];
int money;
int N;

int main(void) {
	int T;
	scanf("%d", &T);
	
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &N, &money);
		money /= 100;
		for (int j = 0; j <= 400; j++) {
			dp[j] = 0;
		}
		ans = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d %d", &cost[j], &want[j]);
			cost[j] /= 100;
		}
		for (int j = 1; j <= 200 && j <= money; j++) {
			for (int k = 1; k <= N; k++) {
				if (cost[k] > j) {
					continue;
				}
				dp[j] = max(dp[j], dp[j - cost[k]] + want[k]);
			}
			ans = max(ans, dp[j]);
		}
		for (int j = 201; j <= money; j++) {
			for (int k = 1; k <= N; k++) {
				dp[j % 400] = max(dp[j % 400], dp[(j - cost[k]) % 400] + want[k]);
			}
			ans = max(ans, dp[j % 400]);
		}

		printf("%d\n", ans);
	}
}