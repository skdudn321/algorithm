#include<stdio.h>

int dp_table[510][510];
int graph[510][510];
int max;

int recursion(int x, int y);

int main(void) {
	int N;
	int i, j, temp;

	scanf("%d", &N);

	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= N + 1; j++) {
			graph[i][j] = 1000000000;
		}
	}
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			temp = recursion(i, j);
			max = max > temp ? max : temp;
		}
	}

	printf("%d", max);
}

int recursion(int x, int y) {
	int temp = 0, t_max = 0;
	if (dp_table[x][y] != 0) {
		return dp_table[x][y];
	}

	if (graph[x + 1][y] < graph[x][y]) {
		temp = recursion(x + 1, y);
		t_max = t_max > temp ? t_max : temp;
	}
	if (graph[x - 1][y] < graph[x][y]) {
		temp = recursion(x - 1, y);
		t_max = t_max > temp ? t_max : temp;
	}
	if (graph[x][y + 1] < graph[x][y]) {
		temp = recursion(x, y + 1);
		t_max = t_max > temp ? t_max : temp;
	}
	if (graph[x][y - 1] < graph[x][y]) {
		temp = recursion(x, y - 1);
		t_max = t_max > temp ? t_max : temp;
	}

	dp_table[x][y] = t_max + 1;
	return dp_table[x][y];
}