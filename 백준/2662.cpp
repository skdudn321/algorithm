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

int dp[301];
int dp2[21][301];
int change[21][301];
int table[21][301];

int main(void) {

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%*d");
		for (int j = 1; j <= M; j++) {
			scanf("%d", &table[j][i]);
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				if (dp[j] < table[i][k] + table[i - 1][j - k]) {
					dp[j] = max(table[i][k] + table[i - 1][j - k], dp[j]);
					for (int y = 0; y <= M; y++) {
						change[y][j] = dp2[y][j - k];
					}
					change[i][j] += k;
				}
			}
			
		}
		for (int j = 1; j <= N; j++) {
			table[i][j] = dp[j];
			dp[j] = 0;
			for (int k = 1; k <= M; k++) {
				dp2[k][j] = change[k][j];
			}
		}
	}
	
	printf("%d\n", table[M][N]);
	for (int k = 1; k <= M; k++) {
		printf("%d ", dp2[k][N]);
	}
}