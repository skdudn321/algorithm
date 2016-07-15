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

int dp[10000001];
int ans = 1;
int maxi = 1;

int recursion(long long int N);

int main(void) {
	for (int i = 1; i <= 10000000; i++) {
		dp[i] = -1;
	}
	dp[1] = 1;
	for (int i = 1; i <= 1000000; i++) {
		if (maxi < recursion(i)) {
			maxi = recursion(i);
			ans = i;
		}
	}
	printf("%d", ans);
}

int recursion(long long int N) {
	if (N <= 10000000 && dp[N] != -1) {
		return dp[N];
	}

	int ret;
	if (N % 2 == 0) {
		ret = recursion(N / 2) + 1;
	}
	else {
		ret = recursion(3 * N + 1) + 1;
	}

	if (N <= 10000000) {
		dp[N] = ret;
	}
	return ret;
}