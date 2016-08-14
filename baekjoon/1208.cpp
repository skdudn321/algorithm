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
int N, S;
int table[41];
lli dp[8000100];

void make_dp(int num);

int main(void) {
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
	}
	sort(table + 1, table + 1 + N);
	for (int i = 1; i <= N; i++) {
		make_dp(i);
	}
	printf("%lld", dp[S + 4000010]);
}

void make_dp(int num) {
	num = table[num];
	if (num < 0) {
		for (int i = -4000010 - num; i <= 4000010; i++) {
			if (dp[i + 4000010] != 0) {
				dp[i + 4000010 + num] += dp[i + 4000010];
			}
		}
	}
	else {
		for (int i = 4000010 - num; i >= -4000010; i--) {
			if (dp[i + 4000010] != 0) {
				dp[i + 4000010 + num] += dp[i + 4000010];
			}
		}
	}
	dp[num + 4000010]++;
}