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

	int V, E, sta;

	scanf("%d %d %d", &V, &E, &sta);

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
		pq[0].push(ii(value, y));
		map[1][y][x] = value;
		pq[1].push(ii(value, x));
	}

	while (!pq[0].empty()){
		if (check[0][pq[0].top().second] == false){
			pq[0].pop();
			continue;
		}
		for (int i = 1; i <= V; i++){
			if (map[0][sta][i] > map[0][sta][pq[0].top().second] + map[0][pq[0].top().second][i]){
				map[0][sta][i] = map[0][sta][pq[0].top().second] + map[0][pq[0].top().second][i];
				pq[0].push(ii(map[0][sta][i], i));
			}
		}
		pq[0].pop();
	}

	while (!pq[1].empty()){
		if (check[1][pq[1].top().second] == false){
			pq[1].pop();
			continue;
		}
		for (int i = 1; i <= V; i++){
			if (map[1][sta][i] > map[1][sta][pq[1].top().second] + map[1][pq[1].top().second][i]){
				map[1][sta][i] = map[1][sta][pq[1].top().second] + map[1][pq[1].top().second][i];
				pq[1].push(ii(map[1][sta][i], i));
			}
		}
		pq[1].pop();
	}

	int ans = 0;
	for (int i = 1; i <= V; i++){
		ans = max(ans, map[0][sta][i] + map[1][sta][i]);
	}
	printf("%d", ans);
}