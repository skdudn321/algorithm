#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int coin[21];
int dp[10001];

int main(void) {
	int T;
	int N;
	int cost;
	int i, j, k;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (j = 1; j <= N; j++) {
			scanf("%d", &coin[j]);
		}
		scanf("%d", &cost);
		for (j = 1; j <= cost; j++) {
			dp[j] = 0;
		}
		dp[0] = 1;

		for (j = 1; j <= N; j++) {
			for (k = 1; k <= cost; k++) {
				if (k >= coin[j]) {
					dp[k] += dp[k - coin[j]];
				}
			}
		}

		printf("%d\n", dp[cost]);
	}


}