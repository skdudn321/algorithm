#include<stdio.h>
#include<queue>

using namespace std;

int N, M;
int MIRO[150][150];
int check[150][150];
int answer;
void bfs(void);
queue<int> qu;

int main(void) {
	int i, j;

	scanf("%d %d", &N, &M);
	getchar();
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			MIRO[i][j] = getchar();
			MIRO[i][j] -= '0';
		}
		getchar();
	}

	qu.push(1);
	qu.push(1);
	qu.push(1);
	check[1][1] = 1;

	while (answer == 0) {
		bfs();
	}

	printf("%d", answer);
}

void bfs(void) {
	int x, y, level;
	x = qu.front();
	qu.pop();
	y = qu.front();
	qu.pop();
	level = qu.front();
	qu.pop();

	if (x == N && y == M) {
		answer = level;
	}

	if (MIRO[x + 1][y] && !check[x + 1][y]) {
		check[x + 1][y] = 1;
		qu.push(x + 1);
		qu.push(y);
		qu.push(level + 1);
	}
	if (MIRO[x - 1][y] && !check[x - 1][y]) {
		check[x - 1][y] = 1;
		qu.push(x - 1);
		qu.push(y);
		qu.push(level + 1);
	}
	if (MIRO[x][y + 1] && !check[x][y + 1]) {
		check[x][y + 1] = 1;
		qu.push(x);
		qu.push(y + 1);
		qu.push(level + 1);
	}
	if (MIRO[x][y - 1] && !check[x][y - 1]) {
		check[x][y - 1] = 1;
		qu.push(x);
		qu.push(y - 1);
		qu.push(level + 1);
	}
}