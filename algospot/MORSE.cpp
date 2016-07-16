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
long long int dp[201][201];
void recursion(int n, int m, long long int k);
int table[201];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= 200; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			if (dp[i - 1][j] + dp[i - 1][j - 1] > 100000000000) {
				dp[i][j] = 100000000000;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}

	for (int i = 1; i <= T; i++) {
		int N, M, C;
		for (int i = 0; i <= 200; i++) {
			table[i] = -1;
		}
		scanf("%d %d %d", &N, &M, &C);
		recursion(N, M, C);
		for (int i = 200; i >= 1; i--) {
			if (table[i] == 0) {
				printf("-");
			}
			else if (table[i] == 1) {
				printf("o");
			}
		}
		printf("\n");
	}
}

void recursion(int n, int m, long long int k) {
	if (n == 0 && m == 0) {
		return;
	}
	else if (n == 0) {
		table[n + m] = 1;
		recursion(n, m - 1, k);
		return;
	}
	else if (m == 0) {
		table[n + m] = 0;
		recursion(n - 1, m, k);
		return;
	}

	if (dp[n + m - 1][n - 1] < k) {
		table[n + m] = 1;
		recursion(n, m - 1, k - dp[n + m - 1][n - 1]);
	}
	else {
		table[n + m] = 0;
		recursion(n - 1, m, k);
	}
}