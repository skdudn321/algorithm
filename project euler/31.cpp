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
int dp[8][201];
int table[8] = { 1,2,5,10,20,50,100,200 };


int main(void) {
	for (int i = 0; i <= 200; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= 7; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < table[i]; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = table[i]; j <= 200; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - table[i]];
		}
	}

	printf("%d", dp[7][200]);
}