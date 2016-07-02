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

int dp[2002][2002];
int table[2][2001];

int ans = 0;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[0][i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[1][i]);
	}

	for (int i = 0; i <= N + 1; i++) {
		dp[i][0] = -1;
		dp[0][i] = -1;
	}
	dp[0][0] = 0;

	for (int i = 1; i <= N + 1; i++) {
		for (int j = 1; j <= N + 1; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]);
			if (dp[i - 1][j] != -1 && table[1][i - 1] < table[0][j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + table[1][i - 1]);
				ans = max(ans, dp[i][j]);
			}
		}
	}

	printf("%d", ans);
}