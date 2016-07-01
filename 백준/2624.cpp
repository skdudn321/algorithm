#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

typedef pair<int, int> aa;

int T, N;
int dp[101][10010];
aa coin[101];

int main(void) {
	int i, j, k;
	int a, b;

	scanf("%d %d", &T, &N);

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &a, &b);
		coin[i] = aa(a, b);
	}

	dp[0][0] = 1;

	for (i = 1; i <= N; i++) {
		for (j = 0; j <= T; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (j = T; j >= 1; j--) {
			for (k = 1; k <= coin[i].second; k++) {
				if (coin[i].first * k > j) {
					break;
				}
				dp[i][j] += dp[i][j - coin[i].first * k];
			}
		}
	}

	printf("%d", dp[N][T]);
}