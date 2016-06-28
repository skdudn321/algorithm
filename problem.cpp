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

int ans;

long long int dp[70];

int main(void) {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 67; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		printf("%lld\n", dp[t]);
	}
}