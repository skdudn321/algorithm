#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<tuple>

using namespace std;

typedef tuple<int, int, int, int> ii;

queue<ii> qu;
int map[1010][1010];
int N, M;
int ans = 2000000000;
int xx[4] = { 1, -1, 0, 0 };
int yy[4] = { 0, 0, 1, -1 };
int check[1010][1010][2];

void bfs(int x, int y, int count, int level);

int main(void){
	scanf("%d %d", &N, &M);

	for (int i = 0; i < 1010; i++){
		for (int j = 0; j < 1010; j++){
			check[i][j][1] = 2000000000;
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	qu.push(make_tuple(1, 1, 0, 1));
	while (!qu.empty()){
		bfs(get<0>(qu.front()), get<1>(qu.front()), get<2>(qu.front()), get<3>(qu.front()));
		qu.pop();
	}
	printf("-1");
}

void bfs(int x, int y, int count, int level){
	if (x == N && y == M){
		printf("%d", level);
		exit(0);
	}
	if (map[x][y] == 1){
		map[x][y] = 3;
	}
	if (map[x][y] == 0){
		map[x][y] = 2;
	}
	check[x][y][0] = count;
	check[x][y][1] = level;

	for (int i = 0; i < 4; i++){
		if (map[x + xx[i]][y + yy[i]] == 0){
			qu.push(make_tuple(x + xx[i], y + yy[i], count, level + 1));
		}
		else if (map[x + xx[i]][y + yy[i]] == 1){
			if (count == 0){
				qu.push(make_tuple(x + xx[i], y + yy[i], 1, level + 1));
			}
		}
		else if (map[x + xx[i]][y + yy[i]] == 2){
			if ((count == 0 && check[x + xx[i]][y + yy[i]][0] == 1) || level + 1 < check[x + xx[i]][y + yy[i]][1]){
				qu.push(make_tuple(x + xx[i], y + yy[i], count, level + 1));
			}
		}
		else if (map[x + xx[i]][y + yy[i]] == 3){
			if (count == 0 && level + 1 < check[x + xx[i]][y + yy[i]][1]){
				qu.push(make_tuple(x + xx[i], y + yy[i], 1, level + 1));
			}
		}
	}

}