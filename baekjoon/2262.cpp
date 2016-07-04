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

ii dp[300][300];

int yang(int a);

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		dp[1][i] = ii(0, temp);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - i + 1; j++) {
			dp[i][j] = ii(dp[i - 1][j + 1].first + dp[1][j].first + yang(dp[i - 1][j + 1].second - dp[1][j].second), min(dp[1][j].second, dp[i - 1][j + 1].second));
			for (int k = 2; k < i; k++) {
				if (dp[i][j].first > dp[i - k][j + k].first + dp[k][j].first + yang(dp[i - k][j + k].second - dp[k][j].second)) {
					dp[i][j] = ii(dp[i - k][j + k].first + dp[k][j].first + yang(dp[i - k][j + k].second - dp[k][j].second), min(dp[k][j].second, dp[i - k][j + k].second));
				}
			}
		}
	}

	ans = dp[N][1].first;
	printf("%d", ans);
}

int yang(int a) {
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}