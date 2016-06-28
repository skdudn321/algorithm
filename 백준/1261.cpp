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

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

typedef pair<int, int> ii;

int map[102][102];
int num[102][102];

int ans;
queue<ii> qu;

int xx[4] = { 1, -1, 0, 0 };
int yy[4] = { 0, 0, 1, -1 };

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i <= M; i++) {
		map[i][0] = -1;
		map[i][N + 1] = -1;
	}
	for (int i = 0; i <= N; i++) {
		map[0][i] = -1;
		map[M + 1][i] = -1;
	}
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
			num[i][j] = int_max;
		}
	}

	qu.push(ii(1, 1));
	num[1][1] = 0;

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		for (int i = 0; i < 4; i++) {
			if (map[x + xx[i]][y + yy[i]] == 0) {
				if (num[x + xx[i]][y + yy[i]] > num[x][y]) {
					qu.push(ii(x + xx[i], y + yy[i]));
					num[x + xx[i]][y + yy[i]] = num[x][y];
				}
			}
			else {
				if (num[x + xx[i]][y + yy[i]] > num[x][y] + 1) {
					qu.push(ii(x + xx[i], y + yy[i]));
					num[x + xx[i]][y + yy[i]] = num[x][y] + 1;
				}
			}
		}
		qu.pop();
	}

	printf("%d", num[M][N]);
}