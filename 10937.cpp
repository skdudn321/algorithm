#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int ans;
int value[13][13][13][13];
int can[13][13][13][13];
vector<ii> graph[13][13];
int xx[4] = { 1, -1, 0, 0 };
int yy[4] = { 0, 0, -1, 1 };
int map[13][13];
int get_value[4][4] = { {100, 70, 40, 0}, {70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0} };

bool mcmf();

int main(void) {
	freopen("test.txt", "r", stdin);
	int N;

	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char temp = getchar();
			if (temp == 'F') {
				map[i][j] = 3;
			}
			else {
				map[i][j] = temp - 'A';
			}
		}
		getchar();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((i + j) % 2 == 0) {
				graph[0][0].push_back(ii(i, j));
				can[0][0][i][j] = 1;
				for (int k = 0; k <= 3; k++) {
					if (i + xx[k] >= 1 && i + xx[k] <= N) {
						if (j + yy[k] >= 1 && j + yy[k] <= N) {
							graph[i][j].push_back(ii(i + xx[k], j + yy[k]));
							graph[i + xx[k]][j + yy[k]].push_back(ii(i, j));
							can[i][j][i + xx[k]][j + yy[k]] = 1;
							value[i][j][i + xx[k]][j + yy[k]] = get_value[map[i][j]][map[i + xx[k]][j + yy[k]]];
							value[i + xx[k]][j + yy[k]][i][j] = -value[i][j][i + xx[k]][j + yy[k]];
						}
					}
				}
			}
			else {
				graph[i][j].push_back(ii(12, 12));
				can[i][j][12][12] = 1;
			}
		}
	}

	while (mcmf());

	printf("%d", -ans);
}

bool mcmf() {
	int velman[13][13];
	ii parent[13][13];
	queue<ii> qu;
	bool change = true;

	for (int i = 0; i <= 12; i++) {
		for (int j = 0; j <= 12; j++) {
			velman[i][j] = 1000000000;
			parent[i][j] = ii(-1, -1);
		}
	}

	qu.push(ii(0, 0));
	velman[0][0] = 0;
	parent[0][0] = ii(0, 0);

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		for (int j = 0; j < graph[x][y].size(); j++) {
			int des_x = graph[x][y][j].first;
			int des_y = graph[x][y][j].second;
			if (can[x][y][des_x][des_y] <= 0) {
				continue;
			}
			if (velman[des_x][des_y] > velman[x][y] - value[x][y][des_x][des_y]) {
				velman[des_x][des_y] = velman[x][y] - value[x][y][des_x][des_y];
				qu.push(ii(des_x, des_y));
				parent[des_x][des_y] = ii(x, y);
			}
		}
	}

	if (velman[12][12] >= 0) {
		return false;
	}
	else {
		int x = 12;
		int y = 12;
		ans += velman[12][12];
		while (parent[x][y].first != x || parent[x][y].second != y) {
			ii next = parent[x][y];

			can[next.first][next.second][x][y]--;
			can[x][y][next.first][next.second]++;

			x = next.first;
			y = next.second;
		}
		return true;
	}
}