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

int house[3];
int dp[1001][3];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &house[0], &house[1], &house[2]);
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + house[2];
	}

	printf("%d", min(min(dp[N][0], dp[N][1]), dp[N][2]));
}