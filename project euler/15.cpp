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
long long int dp[50][50];

long long int recursion(int i, int j);

int main(void) {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= 50; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	printf("%lld", recursion(40, 20));
}

long long int recursion(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	long long int ret;

	ret = recursion(i - 1, j - 1) + recursion(i - 1, j);
	dp[i][j] = ret;
	return ret;
}