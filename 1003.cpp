#include<stdio.h>

int dp_table[50][2];
int recursion(int x);

int main(void){
	int T, N;
	int i;

	dp_table[0][0] = 1;
	dp_table[0][1] = 0;
	dp_table[1][0] = 0;
	dp_table[1][1] = 1;

	for (i = 2; i <= 40; i++){
		dp_table[i][0] = dp_table[i - 1][0] + dp_table[i - 2][0];
		dp_table[i][1] = dp_table[i - 1][1] + dp_table[i - 2][1];
	}

	scanf("%d", &T);
	for (i = 1; i <= T; i++){
		scanf("%d", &N);
		printf("%d %d", dp_table[N][0], dp_table[N][1]);
		if (i != T){
			printf("\n");
		}
	}
}