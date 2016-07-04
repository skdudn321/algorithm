#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

#define oo 100000000

using namespace std;

typedef pair<int, int> ii;

priority_queue<ii, vector<ii>, greater<ii> > pq[2];
int map[2][1001][1001];
bool check[2][1001];

int main(void){

	int V, E, N, M;

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			if (i == j){
				map[0][i][j] = 0;
				map[1][i][j] = 0;
			}
			else{
				map[0][i][j] = oo;
				map[1][i][j] = oo;
			}
		}
		check[0][i] = true;
		check[1][i] = true;
	}

	for (int i = 0; i < E; i++){
		int x, y, value;
		scanf("%d %d %d", &x, &y, &value);
		map[0][x][y] = value;
		map[0][y][x] = value;
		map[1][x][y] = value;
		map[1][y][x] = value;
	}

	scanf("%d %d", &N, &M);
	check[0][N] = false;
	check[1][M] = false;

	for (int i = 1; i <= V; i++){
		if (map[0][N][i] != oo){
			pq[0].push(ii(map[0][N][i], i));
		}
		if (map[1][M][i] != oo){
			pq[1].push(ii(map[1][M][i], i));
		}
	}

	while (!pq[0].empty()){
		if (check[0][pq[0].top().second] == false){
			pq[0].pop();
			continue;
		}
		for (int i = 1; i <= V; i++){
			if (map[0][N][i] > map[0][N][pq[0].top().second] + map[0][pq[0].top().second][i]){
				map[0][N][i] = map[0][N][pq[0].top().second] + map[0][pq[0].top().second][i];
				pq[0].push(ii(map[0][N][i], i));
			}
		}
		check[0][pq[0].top().second] = true;
		pq[0].pop();
	}

	while (!pq[1].empty()){
		if (check[1][pq[1].top().second] == false){
			pq[1].pop();
			continue;
		}
		for (int i = 1; i <= V; i++){
			if (map[1][M][i] > map[1][M][pq[1].top().second] + map[1][pq[1].top().second][i]){
				map[1][M][i] = map[1][M][pq[1].top().second] + map[1][pq[1].top().second][i];
				pq[1].push(ii(map[1][M][i], i));
			}
		}
		check[1][pq[1].top().second] = true;
		pq[1].pop();
	}

	int ans = min(map[0][N][M] + map[0][N][1] + map[1][M][V], map[1][M][N] + map[1][M][1] + map[0][N][V]);

	if (ans >= oo){
		printf("-1");
	}
	else{
		printf("%d", ans);
	}
}