#include<stdio.h>
#include<vector>

int check[51];
int dp_table[51][51][102];

int main(void) {
	int N, M, D, S;
	int p, m, t;
	int ans = 0, sum;

	scanf("%d %d %d %d", &N, &M, &D, &S);

	for (int i = 0; i < D; i++) {
		scanf("%d %d %d", &p, &m, &t);
		for (int j = t + 1; j <= 101; j++) {
			dp_table[p][m][j] = 1;
		}
	}
	for (int i = 0; i < S; i++) {
		scanf("%d %d", &p, &t);
		for (int j = 1; j <= 50; j++) {
			if (dp_table[p][j][t]) {
				check[j]++;
			}
		}
	}

	for (int i = 1; i <= 50; i++) {
		if (check[i] == S) {
			sum = 0;
			for (int j = 1; j <= 50; j++) {
				if (dp_table[j][i][101]) {
					sum++;
				}
			}
			ans = ans > sum ? ans : sum;
		}
	}

	printf("%d", ans);
}