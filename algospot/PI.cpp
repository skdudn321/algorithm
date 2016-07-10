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
char num[10010];
int dp[10010];
int len;

int recursion(int ind);

int main(void) {
	int T;

	freopen("test.txt", "r", stdin);

	scanf("%d\n", &T);

	for (int i = 1; i <= T; i++) {
		for (int i = 0; i <= 10000; i++) {
			dp[i] = -1;
		}
		scanf("%s\n", num + 1);
		len = strlen(num + 1);
		ans = recursion(1);
		printf("%d\n", ans);
	}


}

int recursion(int ind) {
	if (dp[ind] != -1) {
		return dp[ind];
	}
	if (ind == len + 1) {
		return 0;
	}
	if (ind > len + 1 || ind == len || ind == len - 1) {
		return 2000000000;
	}

	int ret = 2000000000;
	
	if (num[ind] == num[ind + 1] && num[ind + 1] == num[ind + 2]) {
		ret = min(ret, recursion(ind + 3) + 1);
	}
	else if (num[ind] == num[ind + 1] + 1 && num[ind] == num[ind + 2] + 2) {
		ret = min(ret, recursion(ind + 3) + 2);
	}
	else if (num[ind] == num[ind + 1] - 1 && num[ind] == num[ind + 2] - 2) {
		ret = min(ret, recursion(ind + 3) + 2);
	}
	else if (num[ind] == num[ind + 2]) {
		ret = min(ret, recursion(ind + 3) + 4);
	}
	else if (num[ind] - num[ind + 1] == num[ind + 1] - num[ind + 2]) {
		ret = min(ret, recursion(ind + 3) + 5);
	}
	else {
		ret = min(ret, recursion(ind + 3) + 10);
	}

	if (num[ind] == num[ind + 1] && num[ind + 2] == num[ind + 3] && num[ind] == num[ind + 2]) {
		ret = min(ret, recursion(ind + 4) + 1);
	}
	else if (num[ind] == num[ind + 1] + 1 && num[ind + 2] + 2 == num[ind + 3] + 3 && num[ind] == num[ind + 2] + 2) {
		ret = min(ret, recursion(ind + 4) + 2);
	}
	else if (num[ind] == num[ind + 1] - 1 && num[ind + 2] - 2 == num[ind + 3] - 3 && num[ind] == num[ind + 2] - 2) {
		ret = min(ret, recursion(ind + 4) + 2);
	}
	else if (num[ind] == num[ind + 2] && num[ind + 1] == num[ind + 3]) {
		ret = min(ret, recursion(ind + 4) + 4);
	}
	else if (num[ind] - num[ind + 1] == num[ind + 1] - num[ind + 2] && num[ind + 1] - num[ind + 2] == num[ind + 2] - num[ind + 3]) {
		ret = min(ret, recursion(ind + 4) + 5);
	}
	else {
		ret = min(ret, recursion(ind + 4) + 10);
	}

	if (num[ind] == num[ind + 1] && num[ind + 2] == num[ind + 3] && num[ind] == num[ind + 4] && num[ind] == num[ind + 2]) {
		ret = min(ret, recursion(ind + 5) + 1);
	}
	else if (num[ind] == num[ind + 1] + 1 && num[ind + 2] + 2 == num[ind + 3] + 3 && num[ind] == num[ind + 4] + 4 && num[ind] == num[ind + 2] + 2) {
		ret = min(ret, recursion(ind + 5) + 2);
	}
	else if (num[ind] == num[ind + 1] - 1 && num[ind + 2] - 2 == num[ind + 3] - 3 && num[ind] == num[ind + 4] - 4 && num[ind] == num[ind + 2] - 2) {
		ret = min(ret, recursion(ind + 5) + 2);
	}
	else if (num[ind] == num[ind + 2] && num[ind] == num[ind + 4] && num[ind + 1] == num[ind + 3]) {
		ret = min(ret, recursion(ind + 5) + 4);
	}
	else if (num[ind] - num[ind + 1] == num[ind + 1] - num[ind + 2] && num[ind + 2] - num[ind + 3] == num[ind + 3] - num[ind + 4] && num[ind] - num[ind + 1] == num[ind + 2] - num[ind + 3]) {
		ret = min(ret, recursion(ind + 5) + 5);
	}
	else {
		ret = min(ret, recursion(ind + 5) + 10);
	}
	dp[ind] = ret;
	return ret;
}