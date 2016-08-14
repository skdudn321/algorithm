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
int dfs(int num, int parent, int me);
vector<int> graph[1000001];
int dp[1000001][2];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i <= N; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	for (int i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	ans = dfs(1, 0, 1);
	ans = min(ans, dfs(1, 0, 0));

	printf("%d", ans);
}

int dfs(int num, int parent, int me) {
	if (dp[num][me] != -1) {
		return dp[num][me];
	}

	int ret = me;

	if (me == 0) {
		for (int i = 0; i < graph[num].size(); i++) {
			if (graph[num][i] != parent) {
				ret += dfs(graph[num][i], num, 1);
			}
		}
	}
	else {
		for (int i = 0; i < graph[num].size(); i++) {
			int temp;
			if (graph[num][i] != parent) {
				temp = dfs(graph[num][i], num, 1);
				temp = min(temp, dfs(graph[num][i], num, 0));
				ret += temp;
			}
		}
	}

	dp[num][me] = ret;
	return ret;
}