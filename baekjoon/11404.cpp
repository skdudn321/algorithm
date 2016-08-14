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
int N, M;
int graph[101][101];
bool check[101];

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = 1000000000;
		}
		graph[i][i] = 0;
	}
	for (int i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		graph[t1][t2] = min(graph[t1][t2], t3);
	}
	for (int i = 1; i <= N; i++) {
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] != 0) {
				pq.push(ii(graph[i][j], j));
			}
		}
		for (int j = 1; j <= N; j++) {
			check[j] = false;
		}
		check[i] = true;
		while (!pq.empty()) {
			ii temp = pq.top();
			pq.pop();
			if (check[temp.second]) {
				continue;
			}
			check[temp.second] = true;
			for (int j = 1; j <= N; j++) {
				if (graph[temp.second][j] != 0) {
					if (graph[i][j] > graph[i][temp.second] + graph[temp.second][j]) {
						graph[i][j] = graph[i][temp.second] + graph[temp.second][j];
						pq.push(ii(graph[i][j], j));
					}
				}
			}
		}
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] >= 1000000000) {
				printf("0 ");
			}
			else {
				printf("%d ", graph[i][j]);
			}
		}
		printf("\n");
	}
}