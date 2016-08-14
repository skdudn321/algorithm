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
typedef pair<ii, int> jj;

int ans;
int N;
bool check[301][301];
ii start, finish;
ii can_move[8] = {ii(1, 2), ii(2, 1), ii(2, -1), ii(1, -2), ii(-1, -2), ii(-2, -1), ii(-2, 1), ii(-1, 2)};

void bfs();

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				check[i][j] = false;
			}
		}
		scanf("%d %d %d %d", &start.first, &start.second, &finish.first, &finish.second);
		start.first++;
		start.second++;
		finish.first++;
		finish.second++;
		ans = -1;
		bfs();
		printf("%d\n", ans);
	}
}

void bfs(void) {
	queue<jj> qu;

	qu.push(jj(start, 0));

	while (!qu.empty()) {
		jj temp = qu.front();
		qu.pop();
		if (check[temp.first.first][temp.first.second]) {
			continue;
		}
		if (temp.first.first == finish.first && temp.first.second == finish.second) {
			ans = temp.second;
			return;
		}
		check[temp.first.first][temp.first.second] = true;
		for (int i = 0; i < 8; i++) {
			if (temp.first.first + can_move[i].first >= 1 && temp.first.first + can_move[i].first <= N) {
				if (temp.first.second + can_move[i].second >= 1 && temp.first.second + can_move[i].second <= N) {
					if (!check[temp.first.first + can_move[i].first][temp.first.second + can_move[i].second]) {
						qu.push(jj(ii(temp.first.first + can_move[i].first, temp.first.second + can_move[i].second), temp.second + 1));
					}
				}
			}
		}
	}
}