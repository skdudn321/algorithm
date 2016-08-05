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
int V, E;
bool check[10001];
bool cancel[10001];
int dfn[10001];
int low[10001];
int ind;

vector<int> graph[10001];

int recursion(int num, int parent);

int main(void) {
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	dfn[0] = -1;
	for (int i = 1; i <= V; i++) {
		if (check[i] == false) {
			recursion(i, 0);
		}
	}

	for (int i = 1; i <= V; i++) {
		if (cancel[i]) {
			ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= V; i++) {
		if (cancel[i]) {
			printf("%d ", i);
		}
	}
}

int recursion(int num, int parent) {
	if (check[num]) {
		return low[num];
	}
	int cou = 0;
	check[num] = true;
	dfn[num] = ind++;
	low[num] = dfn[num];

	for (int i = 0; i < graph[num].size(); i++) {
		if (!check[graph[num][i]]) {
			cou++;
		}
		if (graph[num][i] != parent) {
			int temp_low = recursion(graph[num][i], num);
			low[num] = min(low[num], temp_low);
		}
	}
	if (parent == 0) {
		if (cou >= 2) {
			cancel[num] = true;
		}
		else {
			cancel[num] = false;
		}
	}
	if (dfn[parent] <= low[num]) {
		cancel[parent] = true;
	}

	return low[num];
}