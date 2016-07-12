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
int dp[101][101];

int recursion(int N, int M);

int main(void) {
	int T;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= 100; i++) {
		dp[i][i] = 1;
	}
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			ans = (ans + recursion(N, i)) % 10000000;
		}
		printf("%d\n", ans);
	}
}

int recursion(int N, int M) {
	if (dp[N][M] != -1) {
		return dp[N][M];
	}

	int ret = 0;
	for (int i = 1; i <= N - M; i++) {
		ret = (ret + (i + M - 1) * recursion(N - M, i)) % 10000000;
	}
	dp[N][M] = ret;
	return ret;
}