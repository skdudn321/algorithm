#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<functional>
#include<math.h>

#define up 0
#define down 1
#define left 2
#define right 3

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;
typedef pair<ii, ii> jj;
typedef pair<jj, int> kk;

int ans;
int N, M;
bool check[1001][1001][4][2];
int map[1002][1002];
int xx[4] = { 0, 0, -1, 1 };
int yy[4] = { 1, -1, 0, 0 };

int bfs(void);

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", bfs());
}

int bfs(void) {
	queue<kk> qu;

	qu.push(kk(jj(ii(1, 1), ii(down, 0)), 0));

	while (!qu.empty()) {
		int x = qu.front().first.first.first;
		int y = qu.front().first.first.second;
		int bang = qu.front().first.second.first;
		int orange = qu.front().first.second.second;
		int cou = qu.front().second;
		qu.pop();
		if (x < 1 || x > N || y < 1 || y > M) {
			continue;
		}
		if (check[x][y][bang][orange]) {
			continue;
		}
		if (map[x][y] == 0) {
			continue;
		}
		if (map[x][y] == 3 && orange == 0) {
			continue;
		}
		if (x == N && y == M) {
			return cou;
		}

		check[x][y][bang][orange] = true;

		if (map[x][y] == 4) {
			if (map[x + xx[bang]][y + yy[bang]] != 0 && !(map[x + xx[bang]][y + yy[bang]] == 3 && orange == 0)) {
				qu.push(kk(jj(ii(x + xx[bang], y + yy[bang]), ii(bang, 0)), cou + 1));
				continue;
			}
		}
		if (map[x][y] == 2) {
			orange = 1;
		}
		for (int i = 0; i <= 3; i++) {
			if (map[x + xx[i]][y + yy[i]] != 0 && !(map[x + xx[i]][y + yy[i]] == 3 && orange == 0)) {
				qu.push(kk(jj(ii(x + xx[i], y + yy[i]), ii(i, orange)), cou + 1));
			}
		}
	}

	return -1;
}