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

vector<int> graph[20001];
bool check[20001];
int lr[20001];
bool ans;

void dfs(int num, int parent, int ind);

int main(void) {
	int T;
	int V, E;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d %d", &V, &E);
		ans = true;
		for (int i = 1; i <= V; i++) {
			graph[i].clear();
			lr[i] = 0;
			check[i] = false;
		}
		for (int i = 1; i <= E; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			graph[t1].push_back(t2);
			graph[t2].push_back(t1);
		}

		for (int i = 1; i <= V; i++) {
			if (!check[i]) {
				dfs(i, 0, -1);
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

void dfs(int num, int parent, int ind) {
	check[num] = true;
	lr[num] = ind;

	for (int i = 0; i < graph[num].size(); i++) {
		if (graph[num][i] == parent) {
			continue;
		}
		if (lr[graph[num][i]] == ind) {
			ans = false;
			continue;
		}
		if (!check[graph[num][i]]) {
			dfs(graph[num][i], num, -ind);
		}
	}
}