#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int sum_a, sum_b, min_a = 1000000000, min_b = 1000000000;
int table[2][10001];
int dp[2][10001];

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		table[0][a]++;
		table[1][b]++;
	}

	for (int i = 1; i <= N; i++) {
		sum_a += table[0][i] * (i - 1);
		sum_b += table[1][i] * (i - 1);
	}

	for (int i = 1; i <= N; i++) {
		table[0][i] += table[0][i - 1];
		table[1][i] += table[1][i - 1];
	}

	dp[0][1] = sum_a;
	dp[1][1] = sum_b;
	for (int i = 2; i <= N; i++) {
		dp[0][i] = dp[0][i - 1] + (2 * table[0][i - 1]) - M;
		min_a = min(min_a, dp[0][i]);
		dp[1][i] = dp[1][i - 1] + (2 * table[1][i - 1]) - M;
		min_b = min(min_b, dp[1][i]);
	}

	printf("%d", min_a + min_b);
}