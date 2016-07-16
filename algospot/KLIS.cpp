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

typedef pair<int, long long int> ii;

int ans;
int table[501];
ii dp[501];
int print_table[501];
int N, K;

long long int recursion(int num, int start_index, int length, long long int count);

int main(void) {
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		
		scanf("%d %d", &N, &K);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[j]);
			dp[j] = ii(1, 0);
		}
		ans = 0;
		for (int j = N; j >= 1; j--) {
			for (int k = j + 1; k <= N; k++) {
				if (table[j] < table[k]) {
					dp[j].first = max(dp[j].first, dp[k].first + 1);
				}
				ans = max(dp[j].first, ans);
			}
			if (dp[j].first == 1) {
				dp[j].second = 1;
			}
			for (int k = j + 1; k <= N; k++) {
				if (table[j] < table[k] && dp[j].first == dp[k].first + 1) {
					dp[j].second = dp[j].second + dp[k].second;
				}
				if (dp[j].second > 20000000000) {
					dp[j].second = 20000000000;
					break;
				}
			}
		}
		printf("%d\n", ans);
		recursion(0, 1 , ans, 0);
	}
}

long long int recursion(int num, int start_index, int length, long long int count) {
	if (length == 0) {
		count++;
		if (count == K) {
			for (int i = ans; i >= 1; i--) {
				printf("%d ", print_table[i]);
			}
			printf("\n");
		}
		return count;
	}
	priority_queue<int> pq;
	for (int i = start_index; i <= N; i++) {
		if (table[i] > num && dp[i].first == length) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int i = pq.top();
		pq.pop();
		if (dp[i].second + count < K) {
			count += dp[i].second;
			continue;
		}
		print_table[length] = table[i];
		count = recursion(table[i], i + 1, length - 1, count);
		if (count >= K) {
			return count;
		}
	}

	return count;
}