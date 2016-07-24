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
int table[51];
int dp[51][51][2];
int N;

int recursion(int start, int end, int turn);

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[j]);
		}
		for (int j = 0; j <= 50; j++) {
			for (int k = 0; k <= 50; k++) {
				dp[j][k][0] = -2000000000;
				dp[j][k][1] = -2000000000;
			}
		}
		printf("%d\n", recursion(1, N, 0));
	}
}

int recursion(int start, int end, int turn) {
	if (dp[start][end][turn] != -2000000000) {
		return dp[start][end][turn];
	}

	if (start == end) {
		return table[start];
	}
	if (start > end) {
		return 0;
	}

	int ret = 2000000000;
	ret = min(recursion(start + 2, end, !turn), ret);
	ret = min(recursion(start, end - 2, !turn), ret);
	ret = min(recursion(start + 1, end, !turn) - table[start], ret);
	ret = min(recursion(start, end - 1, !turn) - table[end], ret);
	dp[start][end][turn] = -ret;
	return -ret;

}