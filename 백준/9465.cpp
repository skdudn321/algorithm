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

int dp[100001][2];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 0; j <= 1; j++) {
			for (int i = 1; i <= N; i++) {
				scanf("%d", &dp[i][j]);
			}
		}
		for (int i = 2; i <= N; i++) {
			dp[i][0] += max(dp[i - 1][1], dp[i - 2][1]);
			dp[i][1] += max(dp[i - 1][0], dp[i - 2][0]);
		}
		printf("%d\n", max(dp[N][0], dp[N][1]));
	}
}