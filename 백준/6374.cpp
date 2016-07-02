#include<stdio.h>

int num[101][101];
int dp_table[101][101];
int dp_table2[101];

int main(void) {
	int N;
	int max, all_max = -1000000000;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp_table[i][j] = dp_table[i - 1][j] + num[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			max = -1000000000;
			for (int k = 1; k <= N; k++) {
				dp_table2[k] = dp_table2[k - 1] + dp_table[i][k] - dp_table[j][k] > dp_table[i][k] - dp_table[j][k] ? dp_table2[k - 1] + dp_table[i][k] - dp_table[j][k] : dp_table[i][k] - dp_table[j][k];
				max = max > dp_table2[k] ? max : dp_table2[k];
			}
			all_max = all_max > max ? all_max : max;
		}
	}

	printf("%d", all_max);
}