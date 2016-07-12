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

int map[51][51];
double dp[101][51];
int ans;

int main(void) {
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N, D, P;
		scanf("%d %d %d", &N, &D, &P);
		for (int j = 0; j <= 50; j++) {
			for (int k = 0; k <= 50; k++) {
				map[j][k] = 0;
			}
		}
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 50; k++) {
				dp[j][k] = 0;
			}
		}
		dp[0][P + 1] = 1;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				scanf("%d", &map[j][k]);
			}
		}
		for (int j = 1; j <= N; j++) {
			int temp = 0;
			for (int k = 1; k <= N; k++) {
				if (map[j][k]) {
					temp++;
				}
			}
			map[j][0] = temp;
		}
		for (int j = 1; j <= D; j++) {
			for (int k = 1; k <= N; k++) {
				for (int x = 1; x <= N; x++) {
					if (map[k][x]) {
						dp[j][x] += dp[j - 1][k] / map[k][0];
					}
				}
			}
		}

		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			int tt;
			scanf("%d", &tt);
			printf("%.8lf ", dp[D][tt + 1]);
		}
		printf("\n");
	}


}