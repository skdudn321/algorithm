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
int dp[1001];

int can_win(int num);

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= 1000; i++) {
		dp[i] = -1;
	}
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	if (can_win(N) == 1) {
		printf("SK");
	}
	else {
		printf("CY");
	}
}

int can_win(int num) {
	if (dp[num] != -1) {
		return(dp[num]);
	}

	if (can_win(num - 1) == 0 || can_win(num - 3) == 0) {
		dp[num] = 1;
		return 1;
	}
	else {
		dp[num] = 0;
		return 0;
	}
}