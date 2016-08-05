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

int ans;
int dp[501][501];
int N;
ii table[501];

int recursion(int a, int b);

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			dp[i][j] = -1;
		}
		dp[i][i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &(table[i].first), &(table[i].second));
	}
	
	printf("%d", recursion(1, N));
}

int recursion(int a, int b) {
	if (dp[a][b] != -1) {
		return dp[a][b];
	}

	lli ret = 200000000000;
	for (int i = a; i < b; i++) {
		ret = min(ret, (lli)recursion(a, i) + recursion(i + 1, b) + table[a].first * table[b].second * table[i].second);
	}

	dp[a][b] = ret;
	return ret;
}