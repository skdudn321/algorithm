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

typedef pair<int, int> aa;
int map[60][60];
int check[60][60];
queue<aa> qu;
int N, M;

void bfs(int x, int y);
void c_clear(void);

int main(void) {
	int temp_max, ans = 0;
	char temp;
	
	scanf("%d %d\n", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
			scanf("%c", &temp);
			if (temp == 'L') {
				map[i][j] = 1;
			}
		}
		getchar();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j]) {
				qu.push(aa(i, j));
				temp_max = 0;
				c_clear();
				check[i][j] = 0;
				while (!qu.empty()) {
					bfs(qu.front().first, qu.front().second);
					temp_max = max(temp_max, check[qu.front().first][qu.front().second]);
					qu.pop();
				}
				ans = max(temp_max, ans);
			}
		}
	}

	printf("%d", ans);
}

void c_clear(void) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			check[i][j] = 100000;
		}
	}
}
void bfs(int x, int y) {
	if (map[x + 1][y]) {
		if (check[x + 1][y] > check[x][y] + 1) {
			check[x + 1][y] = check[x][y] + 1;
			qu.push(aa(x + 1, y));
		}
	}
	if (map[x - 1][y]) {
		if (check[x - 1][y] > check[x][y] + 1) {
			check[x - 1][y] = check[x][y] + 1;
			qu.push(aa(x - 1, y));
		}
	}
	if (map[x][y + 1]) {
		if (check[x][y + 1] > check[x][y] + 1) {
			check[x][y + 1] = check[x][y] + 1;
			qu.push(aa(x, y + 1));
		}
	}
	if (map[x][y - 1]) {
		if (check[x][y - 1] > check[x][y] + 1) {
			check[x][y - 1] = check[x][y] + 1;
			qu.push(aa(x, y - 1));
		}
	}
}