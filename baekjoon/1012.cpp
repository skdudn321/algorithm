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

int map[52][52];
int ans;
void recursion(int x, int y);

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		ans = 0;
		for (int j = 1; j <= K; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[x + 1][y + 1] = 1;
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (map[j][k] == 1) {
					ans++;
					recursion(j, k);
				}
			}
		}
		printf("%d\n", ans);
	}
}

void recursion(int x, int y) {
	map[x][y] = 0;

	if (map[x + 1][y] == 1) {
		recursion(x + 1, y);
	}
	if (map[x - 1][y] == 1) {
		recursion(x - 1, y);
	}
	if (map[x][y + 1] == 1) {
		recursion(x, y + 1);
	}
	if (map[x][y - 1] == 1) {
		recursion(x, y - 1);
	}
}