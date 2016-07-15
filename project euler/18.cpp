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
int table[20][20];
int dp[20][20];

int main(void) {
	freopen("test.txt", "r", stdin);

	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &table[i][j]);
		}
	}
	dp[1][1] = table[1][1];
	for (int i = 2; i <= 15; i++) {
		dp[i][1] = dp[i - 1][1] + table[i][1];
		dp[i][i] = dp[i - 1][i - 1] + table[i][i];
		for (int j = 2; j <= i - 1; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + table[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= 15; i++) {
		ans = max(ans, dp[15][i]);
	}
	printf("%d", ans);
}