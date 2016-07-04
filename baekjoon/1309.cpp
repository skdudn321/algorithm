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

int dp[3];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 1; i < N; i++) {
		int temp0 = (dp[0] + dp[1] + dp[2]) % 9901;
		int temp1 = (dp[0] + dp[2]) % 9901;
		int temp2 = (dp[0] + dp[1]) % 9901;
		dp[0] = temp0;
		dp[1] = temp1;
		dp[2] = temp2;
	}

	printf("%d", (dp[0] + dp[1] + dp[2]) % 9901);
}