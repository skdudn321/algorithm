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
vector<int> graph[10001];
vector<int> re_graph[10001];
vector<int> group_member[10001];
bool check[10001];
int group[10001];
ii num_of_node[10001];
int V, E;
int ind;

void dfs(int num);
void dfs2(int num, int group_num);

int main(void) {
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		re_graph[t2].push_back(t1);
	}

	ind = 1;
	for (int i = 1; i <= V; i++) {
		if (!check[i]) {
			dfs(i);
		}
	}
	sort(num_of_node + 1, num_of_node + 1 + V, greater<ii>());
	ind = 0;
	for (int i = 1; i <= V; i++) {
		if (check[num_of_node[i].second]) {
			dfs2(num_of_node[i].second, ++ind);
		}
	}

	for (int i = 1; i <= V; i++) {
		group_member[group[i]].push_back(i);
	}

	printf("%d\n", ind);

	for (int i = 1; i <= V; i++) {
		if (check[group[i]] == false) {
			for (int j = 0; j < group_member[group[i]].size(); j++) {
				printf("%d ", group_member[group[i]][j]);
			}
			printf("-1\n");
			check[group[i]] = true;
		}
	}
}

void dfs(int num) {
	if (check[num]) {
		return;
	}
	check[num] = true;

	for (int i = 0; i < graph[num].size(); i++) {
		if (!check[graph[num][i]]) {
			dfs(graph[num][i]);
		}
	}
	num_of_node[num] = ii(ind++, num);
}

void dfs2(int num, int group_num) {
	if (!check[num]) {
		return;
	}
	check[num] = false;
	group[num] = group_num;

	for (int i = 0; i < re_graph[num].size(); i++) {
		if (check[re_graph[num][i]]) {
			dfs2(re_graph[num][i], group_num);
		}
	}
}