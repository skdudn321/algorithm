#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int dp[1001][1001];
int N, K;

int recursion(int up, int down);

int main(void) {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}
	scanf("%d %d", &N, &K);
	printf("%d", recursion(N, K));
}

int recursion(int up, int down) {
	if (dp[up][down] != -1) {
		return dp[up][down];
	}

	if (down == 0 || up == down) {
		dp[up][down] = 1;
		return 1;
	}

	int ret = recursion(up - 1, down) + recursion(up - 1, down - 1);
	ret %= 10007;
	dp[up][down] = ret;
	return ret;
}