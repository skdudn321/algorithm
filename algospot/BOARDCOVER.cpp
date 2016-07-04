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

int ans;
char map[30][30];
int N, M;

void recursion(int x, int y, int num);

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int white = 0;
		ans = 0;
		scanf("%d %d\n", &N, &M);
		for (int j = 0; j < 30; j++) {
			for (int k = 0; k < 30; k++) {
				map[j][k] = 0;
			}
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				scanf("%c", &map[j][k]);
				if (map[j][k] == '.') {
					white++;
				}
			}
			getchar();
		}
		if (white % 3 != 0) {
			printf("0\n");
			continue;
		}
		recursion(1, 1, white);
		printf("%d\n", ans);
	}
}

void recursion(int x, int y, int num) {
	if (num == 0) {
		ans++;
		return;
	}
	if (map[x][y] == '.') {
		map[x][y] = '#';
		if (map[x][y + 1] == '.' && map[x + 1][y + 1] == '.') {
			map[x][y + 1] = '#';
			map[x + 1][y + 1] = '#';
			if (y == M) {
				recursion(x + 1, 1, num - 3);
			}
			else {
				recursion(x, y + 1, num - 3);
			}
			map[x][y + 1] = '.';
			map[x + 1][y + 1] = '.';
		}
		if (map[x + 1][y] == '.' && map[x + 1][y + 1] == '.') {
			map[x + 1][y] = '#';
			map[x + 1][y + 1] = '#';
			if (y == M) {
				recursion(x + 1, 1, num - 3);
			}
			else {
				recursion(x, y + 1, num - 3);
			}
			map[x + 1][y] = '.';
			map[x + 1][y + 1] = '.';
		}
		if (map[x + 1][y] == '.' && map[x + 1][y - 1] == '.') {
			map[x + 1][y] = '#';
			map[x + 1][y - 1] = '#';
			if (y == M) {
				recursion(x + 1, 1, num - 3);
			}
			else {
				recursion(x, y + 1, num - 3);
			}
			map[x + 1][y] = '.';
			map[x + 1][y - 1] = '.';
		}
		if (map[x + 1][y] == '.' && map[x][y + 1] == '.') {
			map[x + 1][y] = '#';
			map[x][y + 1] = '#';
			if (y == M) {
				recursion(x + 1, 1, num - 3);
			}
			else {
				recursion(x, y + 1, num - 3);
			}
			map[x + 1][y] = '.';
			map[x][y + 1] = '.';
		}
		map[x][y] = '.';
	}
	else {
		if (y == M) {
			recursion(x + 1, 1, num);
		}
		else {
			recursion(x, y + 1, num);
		}
	}
}