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

int dp[101];

int main(void) {
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 100; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		int ans;
		if (N % 2 == 0) {
			ans = dp[N] - dp[N / 2];
			ans = ans - dp[(N / 2) - 1];
		}
		else {
			ans = dp[N] - dp[N / 2];
		}

		while (ans < 0) {
			ans += 1000000007;
		}
		printf("%d\n", ans);
	}


}