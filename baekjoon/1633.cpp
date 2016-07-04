#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int dp[16][16];

int main(void) {
	char temp;
	int a, b;

	while ( scanf("%d %d", &a, &b) != EOF ) {
		for (int i = 15; i >= 0; i--) {
			for (int j = 15; j > 0; j--) {
				if (i == 0) {
					dp[i][j] = max(dp[i][j], dp[i][j - 1] + b);
				}
                else{
                    dp[i][j] = max(dp[i][j], max(dp[i][j - 1] + b, dp[i -1][j] + a));
                }
			}
			if (i != 0) {
				dp[i][0] = max(dp[i - 1][0] + a, dp[i][0]);
			}
		}
		
	}

	printf("%d", dp[15][15]);
}