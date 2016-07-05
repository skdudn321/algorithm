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

int map[102][102];
int check[102][102];
int ans;

typedef pair<int, int> ii;

queue<ii> qu;

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		ans = 0;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				scanf("%d", &map[j][k]);
				check[j][k] = 0;
			}
		}
		qu.push(ii(1, 1));

		while (!qu.empty()) {
			ii temp = qu.front();
			qu.pop();
			if (temp.first == N && temp.second == N) {
				ans = 1;
			}
			if (ans == 1) {
				continue;
			}
			if (check[temp.first][temp.second] == 1) {
				continue;
			}
			check[temp.first][temp.second] = 1;

			if (temp.first + map[temp.first][temp.second] <= N && check[temp.first + map[temp.first][temp.second]][temp.second] == 0) {
				qu.push(ii(temp.first + map[temp.first][temp.second], temp.second));
			}
			if (temp.second + map[temp.first][temp.second] <= N && check[temp.first][temp.second + map[temp.first][temp.second]] == 0) {
				qu.push(ii(temp.first, temp.second + map[temp.first][temp.second]));
			}
		}
		if (ans == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}