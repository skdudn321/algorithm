#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int ans;
int w, h;
bool graph[52][52];
int xx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int yy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void init(void);
void dfs(int x, int y);

int main(void) {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		init();
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int temp;
				scanf("%d", &temp);
				if (temp == 1) {
					graph[i][j] = true;
				}
				else {
					graph[i][j] = false;
				}
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (graph[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
}

void init(void) {
	ans = 0;
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 51; j++) {
			graph[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	graph[x][y] = false;
	
	for (int i = 0; i <= 7; i++) {
		if (graph[x + xx[i]][y + yy[i]]) {
			dfs(x + xx[i], y + yy[i]);
		}
	}
}