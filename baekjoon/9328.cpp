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
int h, w;
char map[102][102];
bool check[102][102];
bool key[30];
bool get_key;
char temp;
int xx[4] = { 0, 0, 1, -1 };
int yy[4] = { 1, -1, 0, 0 };

void init_check(void);
void dfs(int x, int y);
bool can_start(int x, int y);

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		ans = 0;
		for (int i = 0; i <= 101; i++) {
			for (int j = 0; j <= 101; j++) {
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < 30; i++) {
			key[i] = false;
		}
		get_key = true;
		scanf("%d %d\n", &h, &w);
		for (int i = 1; i <= h; i++) {
			gets_s(map[i] + 1, 101);
		}
		while (1) {
			temp = getchar();
			if (temp == '0' || temp == '\n') {
				break;
			}
			key[temp - 'a' + 1] = true;
		}

		while (get_key) {
			get_key = false;
			init_check();

			for (int i = 1; i <= w; i++) {
				if (can_start(1, i)) {
					dfs(1, i);
				}
				if (can_start(h, i)) {
					dfs(h, i);
				}
			}
			for (int i = 2; i < h; i++) {
				if (can_start(i, 1)) {
					dfs(i, 1);
				}
				if (can_start(i, w)) {
					dfs(i, w);
				}
			}
		}
		printf("%d\n", ans);
	}
}

void init_check(void) {
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			check[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	if (check[x][y]) {
		return;
	}
	if (map[x][y] >= 'A' && map[x][y] <= 'Z') {
		if (key[map[x][y] - 'A' + 1]) {
			map[x][y] = '.';
		}
		else {
			return;
		}
	}
	if (map[x][y] >= 'a' && map[x][y] <= 'z') {
		if (!key[map[x][y] - 'a' + 1]) {
			key[map[x][y] - 'a' + 1] = true;
			get_key = true;
		}
		map[x][y] = '.';
	}
	if (map[x][y] == '$') {
		map[x][y] = '.';
		ans++;
	}

	check[x][y] = true;

	for (int i = 0; i <= 3; i++) {
		if (can_start(x + xx[i], y + yy[i])) {
			dfs(x + xx[i], y + yy[i]);
		}
	}
}

bool can_start(int x, int y) {
	bool ret = !(map[x][y] == 0 || map[x][y] == '*');
	if (check[x][y]) {
		ret = false;
	}

	return ret;
}