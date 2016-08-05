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
int dp[10001][2];
vector<int> graph[10001];
int N;
int table[10001];
int group[10001];

int recursion(int ind, int involve, int parent);
void grouping(int ind, int involve, int parent);

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
	}
	for (int i = 1; i <= N; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	for (int i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	ans = max(recursion(1, 1, 0), recursion(1, 0, 0));
	if (recursion(1, 1, 0) > recursion(1, 0, 0)) {
		grouping(1, 1, 0);
	}
	else {
		grouping(1, 0, 0);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= N; i++) {
		if (group[i] == 1) {
			printf("%d ", i);
		}
	}
}

int recursion(int ind, int involve, int parent) {
	if (dp[ind][involve] != -1) {
		return dp[ind][involve];
	}

	int ret = 0;
	if (graph[ind].size() == 1 && graph[ind][0] == parent) {
		if (involve == 0) {
			dp[ind][involve] = 0;
			return 0;
		}
		else {
			dp[ind][involve] = table[ind];
			return table[ind];
		}
	}
	if (involve == 1) {
		for (int i = 0; i < graph[ind].size(); i++) {
			if (graph[ind][i] != parent) {
				ret += recursion(graph[ind][i], 0, ind);
			}
		}
		ret += table[ind];
	}
	else {
		for (int i = 0; i < graph[ind].size(); i++) {
			if (graph[ind][i] != parent) {
				int temp = recursion(graph[ind][i], 0, ind);
				temp = max(temp, recursion(graph[ind][i], 1, ind));
				ret += temp;
			}
		}
	}

	dp[ind][involve] = ret;
	return ret;
}

void grouping(int ind, int involve, int parent) {
	group[ind] = involve;

	if (graph[ind].size() == 1 && graph[ind][0] == parent) {
		return;
	}
	if (involve == 1) {
		for (int i = 0; i < graph[ind].size(); i++) {
			if (graph[ind][i] != parent) {
				grouping(graph[ind][i], 0, ind);
			}
		}
	}
	else {
		for (int i = 0; i < graph[ind].size(); i++) {
			if (graph[ind][i] != parent) {
				int temp1 = recursion(graph[ind][i], 0, ind);
				int temp2 = recursion(graph[ind][i], 1, ind);
				if (temp1 > temp2) {
					grouping(graph[ind][i], 0, ind);
				}
				else {
					grouping(graph[ind][i], 1, ind);
				}
			}
		}
	}
}