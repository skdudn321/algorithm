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

int N;
int graph[51][51];
bool check[51];

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = 100000000;
		}
		graph[i][i] = 0;
	}
	while(1) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t1 == -1 && t2 == -1) {
			break;
		}
		graph[t1][t2] = 1;
		graph[t2][t1] = 1;
	}

	for (int i = 1; i <= N; i++) {
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		for (int j = 1; j <= N; j++) {
			check[j] = false;
			if (graph[i][j] != 100000000) {
				pq.push(ii(graph[i][j], j));
			}
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
				if (graph[i][j] > graph[i][temp.second] + graph[temp.second][j]) {
					graph[i][j] = graph[i][temp.second] + graph[temp.second][j];
					pq.push(ii(graph[i][j], j));
				}
			}
		}
	}
	int ans = 100000000;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp = max(temp, graph[i][j]);
		}
		graph[i][0] = temp;
		ans = min(temp, ans);
	}
	int cou = 0;
	for (int i = 1; i <= N; i++) {
		if (graph[i][0] == ans) {
			cou++;
		}
	}
	printf("%d %d\n", ans, cou);
	for (int i = 1; i <= N; i++) {
		if (graph[i][0] == ans) {
			printf("%d ", i);
		}
	}
}