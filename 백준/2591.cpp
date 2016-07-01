#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int dp[2][41];
int back;
int cur;

int main(void) {

	int ind = 0;
	dp[0][0] = 1;
	while (scanf("%1d", &cur) != EOF) {
		ind++;
		if (cur != 0) {
			dp[0][ind] = dp[0][ind - 1] + dp[1][ind - 1];
		}
		if (cur + back * 10 >= 10 && cur + back * 10 <= 34) {
			dp[1][ind] = dp[0][ind - 2] + dp[1][ind - 2];
		}
		back = cur;
	}

	printf("%d", dp[0][ind] + dp[1][ind]);
}