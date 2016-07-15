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

int table[2][10001];
int dp[2][10001];

int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		for (int i = 0; i <= 10000; i++) {
			table[0][i] = 0;
			table[1][i] = 0;
			dp[0][i] = 0;
			dp[1][i] = 0;
		}
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &table[0][i]);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d", &table[1][i]);
		}

		dp[0][1] = table[0][1];
		dp[1][1] = table[1][1];
		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + table[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + table[1][i];
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", max(dp[0][N], dp[1][N]));
	}

	return 0;
}