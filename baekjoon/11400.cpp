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
vector<int> graph[100001];
ii group[100001];
int check[100001];
int ind = 1;
vector<ii> edge;

int dfs(int num, int parent);

int main(void) {
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	dfs(1, 0);
	sort(edge.begin(), edge.end());
	printf("%d\n", edge.size());
	for (int i = 0; i < edge.size(); i++) {
		printf("%d %d\n", edge[i].first, edge[i].second);
	}
}

int dfs(int num, int parent) {
	if (group[num].second != 0) {
		return group[num].second;
	}
	group[num].first = ind;
	group[num].second = ind++;
	int ret = group[num].first;

	for (int i = 0; i < graph[num].size(); i++) {
		if (graph[num][i] == parent) {
			continue;
		}
		int temp = dfs(graph[num][i], num);
		if (group[num].first < temp) {
			edge.push_back(ii(min(num, graph[num][i]), max(num, graph[num][i])));
		}
		ret = min(ret, temp);
	}
	group[num].second = ret;
	return ret;
}