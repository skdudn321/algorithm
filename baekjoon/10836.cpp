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

int dp[4][1500];

int main(void) {
	int N, M, K;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		dp[0][t1]++;
		dp[1][t3]++;
	}

	K = 2 * N - 1;
	for (int i = 1; i <= K; i++) {
		dp[0][i] += dp[0][i - 1];
	}
	for (int i = K; i >= 0; i--) {
		dp[1][i] += dp[1][i + 1];
	}

	for (int i = 1; i <= K; i++) {
		dp[3][i] = dp[0][i - 1] + dp[1][K - i + 1] + 1;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", dp[3][N - i]);
		for (int j = 1; j < N; j++) {
			printf("%d ", dp[3][N + j]);
		}
		printf("\n");
	}
}