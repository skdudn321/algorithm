#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int table[1001];
int dp[1001];

int main(void) {
	int T;
	int N;
	int i, j, k;
	int max = 0;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &table[i]);
	}
	
	dp[1] = table[1];
	for (i = 2; i <= T; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (table[j] < table[i]) {
				dp[i] = dp[i] < dp[j] + table[i] ? dp[j] + table[i] : dp[i];
			}
		}
	}

	for (i = 1; i <= T; i++) {
		max = max < dp[i] ? dp[i] : max;
	}

	printf("%d", max);
}