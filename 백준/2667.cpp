#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int num = 1;
int group[1000];
int map[30][30];
int dfs(int x, int y);

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j]) {
				map[i][j] = 0;
				group[num++] = dfs(i, j);
			}
		}
	}

	printf("%d\n", num - 1);
	sort(group + 1, group + num);
	for (int i = 1; i < num; i++) {
		printf("%d\n", group[i]);
	}
}

int dfs(int x, int y) {
	int r_value = 1;
	if (map[x + 1][y] == 1) {
		map[x + 1][y] = 0;
		r_value += dfs(x + 1, y);
	}
	if (map[x - 1][y] == 1) {
		map[x - 1][y] = 0;
		r_value += dfs(x - 1, y);
	}
	if (map[x][y + 1] == 1) {
		map[x][y + 1] = 0;
		r_value += dfs(x, y + 1);
	}
	if (map[x][y - 1] == 1) {
		map[x][y - 1] = 0;
		r_value += dfs(x, y - 1);
	}

	return r_value;
}