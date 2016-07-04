#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int light[102][102];
typedef pair<int, int> ii;
vector<ii> ve[101][101];
queue<ii> qu;

int main(void) {
	int N, M;
	int light_num = 1;
	int x, y, a, b;
	ii ha;

	light[1][1] = 7;
	qu.push(ii(1, 1));

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		ve[x][y].push_back(ii(a, b));
	}

	while (!qu.empty()) {
		ha = qu.front();
		qu.pop();
		light[ha.first - 1][ha.second] |= 2;
		if (light[ha.first - 1][ha.second] == 3) {
			qu.push(ii(ha.first - 1, ha.second));
			light[ha.first - 1][ha.second] |= 4;
		}
		light[ha.first + 1][ha.second] |= 2;
		if (light[ha.first + 1][ha.second] == 3) {
			qu.push(ii(ha.first + 1, ha.second));
			light[ha.first + 1][ha.second] |= 4;
		}
		light[ha.first][ha.second + 1] |= 2;
		if (light[ha.first][ha.second + 1] == 3) {
			qu.push(ii(ha.first, ha.second + 1));
			light[ha.first][ha.second + 1] |= 4;
		}
		light[ha.first][ha.second - 1] |= 2;
		if (light[ha.first][ha.second - 1] == 3) {
			qu.push(ii(ha.first, ha.second - 1));
			light[ha.first][ha.second - 1] |= 4;
		}
		

		for (int i = 0; i < (int)ve[ha.first][ha.second].size(); i++) {
			if ((light[ve[ha.first][ha.second][i].first][ve[ha.first][ha.second][i].second] & 1) == 0) {
				light_num++;
			}
			light[ve[ha.first][ha.second][i].first][ve[ha.first][ha.second][i].second] |= 1;
			if (light[ve[ha.first][ha.second][i].first][ve[ha.first][ha.second][i].second] == 3) {
				qu.push(ii(ve[ha.first][ha.second][i].first, ve[ha.first][ha.second][i].second));
				light[ve[ha.first][ha.second][i].first][ve[ha.first][ha.second][i].second] |= 4;
			}
		}
	}

	printf("%d", light_num);
}