#include<stdio.h>

int train[50001];
int dp_table[4][50001];

int main(void) {
	int N, K;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &train[i]);
	}
	
	scanf("%d", &K);

	for (int i = 1; i <= K; i++) {
		dp_table[0][i] = dp_table[0][i - 1] + train[i];
	}
	for (int i = K + 1; i <= N; i++) {
		dp_table[0][i] = dp_table[0][i - 1] + train[i] - train[i - K];
	}

	for (int i = K; i <= N; i++) {
		dp_table[1][i] = dp_table[1][i - 1] > dp_table[0][i] ? dp_table[1][i - 1] : dp_table[0][i];
	}

	for (int j = 2; j <= 3; j++) {
		for (int i = j * K; i <= N; i++) {
			dp_table[j][i] = dp_table[j][i - 1] > dp_table[0][i] + dp_table[j - 1][i - K] ? dp_table[j][i - 1] : dp_table[0][i] + dp_table[j - 1][i - K];
		}
	}

	printf("%d", dp_table[3][N]);
}