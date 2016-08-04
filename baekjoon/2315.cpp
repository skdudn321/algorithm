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

int N, M;
int elec;
ii table[1001];
int dp[1001][1001][2];

int recursion(int left, int right, int ind, int cur);

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		table[i] = ii(t1, t2);
		elec += t2;
	}

	elec -= table[M].second;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}

	dp[1][N][0] = 0;
	dp[1][N][1] = 0;

	printf("%d", recursion(M, M, 0, elec));
}

int recursion(int left, int right, int ind, int cur) {
	if (dp[left][right][ind] != -1) {
		return dp[left][right][ind];
	}
	int ret;
	int left_move;
	int right_move;
	if (ind == 0) {
		left_move = table[left].first - table[left - 1].first;
		right_move = table[right + 1].first - table[left].first;
	}
	else {
		left_move = table[right].first - table[left - 1].first;
		right_move = table[right + 1].first - table[right].first;
	}

	if (left == 1) {
		ret = recursion(left, right + 1, 1, cur - table[right + 1].second) + cur * right_move;
	}
	else if (right == N) {
		ret = recursion(left - 1, right, 0, cur - table[left - 1].second) + cur * left_move;
	}
	else {
		ret = recursion(left, right + 1, 1, cur - table[right + 1].second) + cur * right_move;
		ret = min(ret, recursion(left - 1, right, 0, cur - table[left - 1].second) + cur * left_move);
	}

	dp[left][right][ind] = ret;
	return ret;
}