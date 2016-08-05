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

typedef struct big_int {
	char num[1001];
}big_int;

int ans;
big_int dp[251];

void big_print(big_int pp);

int main(void) {
	freopen("test.txt", "r", stdin);

	dp[0].num[1000] = 1;
	dp[1].num[1000] = 1;
	dp[2].num[1000] = 3;

	for (int i = 3; i <= 250; i++) {
		int up = 0;
		for (int j = 1000; j >= 0; j--) {
			dp[i].num[j] = dp[i - 1].num[j] + dp[i - 2].num[j] + dp[i - 2].num[j] + up;
			up = dp[i].num[j] / 10;
			dp[i].num[j] %= 10;
		}
	}

	while (scanf("%d", &ans) != EOF) {
		big_print(dp[ans]);
	}
}

void big_print(big_int pp) {
	int i;
	for (i = 0; i <= 1000; i++) {
		if (pp.num[i] != 0) {
			break;
		}
	}

	for (; i <= 1000; i++) {
		printf("%d", (int)(pp.num[i]));
	}
	printf("\n");
}