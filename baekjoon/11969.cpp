#include<stdio.h>

int cow[100010][3];
int dp_table[100010][3];

int main(void) {
	int N, Q, temp, temp2;

	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		cow[i][temp - 1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		dp_table[i][0] = dp_table[i - 1][0] + cow[i][0];
		dp_table[i][1] = dp_table[i - 1][1] + cow[i][1];
		dp_table[i][2] = dp_table[i - 1][2] + cow[i][2];
	}

	for (int i = 1; i <= Q; i++) {
		scanf("%d %d", &temp, &temp2);
		printf("%d %d %d\n", dp_table[temp2][0] - dp_table[temp - 1][0], dp_table[temp2][1] - dp_table[temp - 1][1], dp_table[temp2][2] - dp_table[temp - 1][2]);
	}
}