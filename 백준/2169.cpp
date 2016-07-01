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

int ans;
int map[3][1002][1002];

int main(void) {

	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			map[1][i][j] = int_min;
			map[2][i][j] = int_min;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[0][i][j]);
		}
	}

	map[1][1][1] = map[0][1][1];
	map[2][1][1] = map[0][1][1];

	for (int i = 2; i <= M; i++) {
		map[1][1][i] = map[1][1][i - 1] + map[0][1][i];
		map[2][1][i] = map[1][1][i];
	}

	for (int i = 2; i <= N; i++) {
		map[1][i][1] = max(map[1][i - 1][1], map[2][i - 1][1]) + map[0][i][1];
		for (int j = 2; j <= M; j++) {
			map[1][i][j] = max(map[1][i][j - 1], max(map[1][i - 1][j], map[2][i - 1][j])) + map[0][i][j];
		}
		map[2][i][M] = max(map[1][i - 1][M], map[2][i - 1][M]) + map[0][i][M];
		for (int j = M - 1; j >= 1; j--) {
			map[2][i][j] = max(map[2][i][j + 1], max(map[1][i - 1][j], map[2][i - 1][j])) + map[0][i][j];
		}
	}

	printf("%d", max(map[1][N][M], map[2][N][M]));
}