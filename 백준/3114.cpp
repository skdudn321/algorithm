#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int dp_a[1550][1550];
int dp_b[1550][1550];
int ans[1550][1550];

int main(void) {
	int R, C;
	int i, j, k;
	char temp;
	int temp_value;

	scanf("%d %d\n", &R, &C);

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf("%c%d", &temp, &temp_value);
			getchar();
			if (temp == 'B') {
				dp_b[i][j] = temp_value + dp_b[i - 1][j];
			}
			else {
				dp_a[i][j] = temp_value;
				dp_b[i][j] = dp_b[i - 1][j];
			}
		}
	}

	for (j = 1; j <= C; j++) {
		for (i = R; i >= 1; i--) {
			dp_a[i][j] = dp_a[i + 1][j] + dp_a[i][j];
		}
	}

	for (i = 1; i <= R; i++) {
		ans[i][1] = dp_a[i + 1][1];
	}
	for (j = 1; j <= C; j++) {
		ans[1][j] = ans[1][j - 1] + dp_a[2][j];
	}

	for (j = 2; j <= C; j++) {
		for (i = 2; i <= R; i++) {
			ans[i][j] = max(ans[i - 1][j] - dp_a[i][j] + dp_a[i + 1][j], max(ans[i-1][j-1], ans[i][j-1]) + dp_a[i + 1][j] + dp_b[i - 1][j]);
		}
	}

	printf("%d", ans[R][C]);
}