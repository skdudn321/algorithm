#include<stdio.h>
#include<queue>
#include<algorithm>

#define int_max 2000000000

using namespace std;

typedef pair<int, int> ii;

int tomato[1002][1002];
int ans;
queue<ii> qu;

int xx[4] = { 1, -1, 0, 0 };
int yy[4] = { 0, 0, 1, -1 };

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N + 1; i++) {
		tomato[0][i] = -1;
		tomato[M + 1][i] = -1;
	}
	for (int i = 0; i <= M + 1; i++) {
		tomato[i][0] = -1;
		tomato[i][N + 1] = -1;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				tomato[i][j] = 0;
				qu.push(ii(i, j));
			}
			else if (tomato[i][j] == 0) {
				tomato[i][j] = int_max;
			}
		}
	}

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		for (int i = 0; i < 4; i++) {
			if (tomato[x + xx[i]][y + yy[i]] > tomato[x][y] + 1) {
				tomato[x + xx[i]][y + yy[i]] = tomato[x][y] + 1;
				qu.push(ii(x + xx[i], y + yy[i]));
			}
		}
		qu.pop();
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (tomato[i][j] == int_max) {
				printf("-1");
				return 0;
			}
			else {
				ans = max(tomato[i][j], ans);
			}
		}
	}
	printf("%d", ans);
}