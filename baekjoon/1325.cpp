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
int ind = 1;
bool check[10001];
int group[10001];
int size_of_group[10001];
int table[10001];

vector<int> graph[10001];
vector<int> re_graph[10001];
set<int> scc_graph[10001];
set<int> re_scc_graph[10001];
ii scc[10001];
int group_num;

void dfs(int num);
void dfs2(int num);
int dfs3(int num);

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t2].push_back(t1);
		re_graph[t1].push_back(t2);
	}
	for (int i = 1; i <= N; i++) {
		scc[i].second = i;
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			dfs(i);
		}
	}
	sort(scc + 1, scc + 1 + N, greater<ii>());
	
	group_num = 1;
	for (int i = 1; i <= N; i++) {
		if (check[scc[i].second]) {
			dfs2(scc[i].second);
			group_num++;
		}
	}

	for (int i = 1; i <= N; i++) {
		size_of_group[group[i]]++;
		for (int j = 0; j < graph[i].size(); j++) {
			scc_graph[group[i]].insert(group[graph[i][j]]);
		}
		for (int j = 0; j < re_graph[i].size(); j++) {
			if (group[i] != group[re_graph[i][j]]) {
				re_scc_graph[group[i]].insert(group[re_graph[i][j]]);
			}
		}
	}

	for (int i = 1; i < group_num; i++) {
		for (int j = 1; j < group_num; j++) {
			check[j] = false;
		}
		if (re_scc_graph[i].size() == 0) {
			table[i] = dfs3(i);
			ans = max(ans, table[i]);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (table[group[i]] == ans) {
			printf("%d ", i);
		}
	}
}

void dfs(int num) {
	check[num] = true;

	for (int i = 0; i < graph[num].size(); i++) {
		if (!check[graph[num][i]]) {
			dfs(graph[num][i]);
		}
	}

	scc[num].first = ind++;
}

void dfs2(int num) {
	check[num] = false;
	group[num] = group_num;

	for (int i = 0; i < re_graph[num].size(); i++) {
		if (check[re_graph[num][i]]) {
			dfs2(re_graph[num][i]);
		}
	}
}

int dfs3(int num) {
	check[num] = true;
	int ret = size_of_group[num];

	set<int>::iterator temp_iter = scc_graph[num].begin();
	while (temp_iter != scc_graph[num].end()) {
		if (!check[*temp_iter]) {
			ret += dfs3(*temp_iter);
		}
		temp_iter++;
	}

	return ret;
}