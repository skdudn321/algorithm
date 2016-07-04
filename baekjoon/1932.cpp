#include<stdio.h>

int tri[501][501];
int dp_table[501][501];

int main(void){
	int N;
	int i, j;
	int max = 0;
	
	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++){
			scanf("%d", &tri[i][j]);
		}
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++){
			dp_table[i][j] = dp_table[i - 1][j] > dp_table[i - 1][j - 1] ? dp_table[i - 1][j] : dp_table[i - 1][j - 1];
			dp_table[i][j] += tri[i][j];
		}
	}

	for (i = 1; i <= N; i++){
		if (max < dp_table[N][i]){
			max = dp_table[N][i];
		}
	}

	printf("%d", max);
}