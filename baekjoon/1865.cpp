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

bool ans;
int T;
int N, M, W;
int graph[501][501];
vector<ii> edge[501];
vector<ii> worm[501];
bool velman(int num);

int main(void) {
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d %d %d", &N, &M, &W);
		for (int i = 1; i <= N; i++) {
			worm[i].clear();
			edge[i].clear();
			for (int j = 1; j <= N; j++) {
				graph[i][j] = 0;
			}
		}
		ans = false;
		for (int i = 1; i <= M; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if (graph[t1][t2] != 0) {
				graph[t1][t2] = min(graph[t1][t2], t3);
				graph[t2][t1] = min(graph[t2][t1], t3);
			}
			else {
				graph[t1][t2] = t3;
				graph[t2][t1] = t3;
			}
		}
		for (int i = 1; i <= W; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			graph[t1][t2] = min(-t3, graph[t1][t2]);
			worm[t1].push_back(ii(t2, t3));
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] != 0) {
					edge[i].push_back(ii(j, graph[i][j]));
				}
			}
		}

		for (int i = 1; !ans && i <= N; i++) {
			if (worm[i].size() != 0) {
				ans |= velman(i);
			}
		}

		if (ans) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}

bool velman(int num) {
	int temp[501][501];
	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp[i][j] = 2000000000;
		}
		temp[i][i] = 0;
	}

	for (int i = 1; i <= M; i++) {
		bool change = false;
		for (int j = 1; j <= N; j++) {
			if (temp[num][j] < 1000000000) {
				qu.push(j);
			}
		}
		while (!qu.empty()) {
			int j = qu.front();
			qu.pop();
			for (int k = 0; k < edge[j].size(); k++) {
				if (temp[num][edge[j][k].first] > temp[num][j] + edge[j][k].second) {
					temp[num][edge[j][k].first] = temp[num][j] + edge[j][k].second;
					change |= true;
				}
			}
		}
		if (!change) {
			return false;
		}
	}

	return true;
}