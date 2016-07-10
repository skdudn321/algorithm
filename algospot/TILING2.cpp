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
int dp[101];

int main(void) {
	dp[2] = 2;
	dp[1] = 1;
	for (int i = 3; i <= 100; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}