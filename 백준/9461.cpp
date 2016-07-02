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

long long int dp[101];

int main(void) {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	int N;
	int temp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		printf("%lld\n", dp[temp]);
	}
}