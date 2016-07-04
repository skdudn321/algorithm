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

int dp[2][3];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int j = 1; j <= N; j++) {
		int temp[2][3];
		scanf("%d %d %d", &temp[0][0], &temp[0][1], &temp[0][2]);
		temp[1][0] = temp[0][0];
		temp[1][1] = temp[0][1];
		temp[1][2] = temp[0][2];
		temp[0][0] += max(dp[0][0], dp[0][1]);
		temp[0][1] += max(dp[0][0], max(dp[0][1], dp[0][2]));
		temp[0][2] += max(dp[0][1], dp[0][2]);
		temp[1][0] += min(dp[1][0], dp[1][1]);
		temp[1][1] += min(dp[1][0], min(dp[1][1], dp[1][2]));
		temp[1][2] += min(dp[1][1], dp[1][2]);
		dp[0][0] = temp[0][0];
		dp[0][1] = temp[0][1];
		dp[0][2] = temp[0][2];
		dp[1][0] = temp[1][0];
		dp[1][1] = temp[1][1];
		dp[1][2] = temp[1][2];
	}

	printf("%d %d", max(dp[0][0], max(dp[0][1], dp[0][2])), min(dp[1][0], min(dp[1][1], dp[1][2])));
}