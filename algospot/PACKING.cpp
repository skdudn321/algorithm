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
int ans2;
char name[110][30];
int heavy[110];
int want[110];
int dp[110][1010];
int N, W;
bool check[110];

int recursion(int weigh, int num);
void recursion2(int weigh, int num);

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 1000; k++) {
				dp[j][k] = -1;
			}
			check[j] = false;
		}
		ans2 = 0;
		scanf("%d %d\n", &N, &W);
		for (int j = 1; j <= N; j++) {
			scanf("%s %d %d\n", name[j], &heavy[j], &want[j]);
		}
		ans = recursion(W, 1);
		recursion2(W, 1);
		printf("%d %d\n", ans, ans2);
		for (int j = 1; j <= N; j++) {
			if (check[j]) {
				printf("%s\n", name[j]);
			}
		}
	}
}

int recursion(int weigh, int num) {
	if (num > N) {
		return 0;
	}
	if (dp[num][weigh] != -1) {
		return dp[num][weigh];
	}

	int ret;
	if (weigh < heavy[num]) {
		ret = recursion(weigh, num + 1);
	}
	else {
		ret = recursion(weigh - heavy[num], num + 1) + want[num];
		ret = max(ret, recursion(weigh, num + 1));
	}

	dp[num][weigh] = ret;
	return ret;
}

void recursion2(int weigh, int num) {
	if (num == N) {
		if (dp[num][weigh] != 0) {
			check[num] = true;
			ans2++;
		}
		return;
	}

	if (dp[num][weigh] != dp[num + 1][weigh]) {
		check[num] = true;
		ans2++;
		recursion2(weigh - heavy[num], num + 1);
	}
	else {
		recursion2(weigh, num + 1);
	}
}