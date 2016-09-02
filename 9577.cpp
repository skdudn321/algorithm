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
vector<int> left[101];
int match[101];
bool check[101];

void init(void);
bool dfs(int ind);

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int C = 1; C <= T; C++) {

		init();

		scanf("%d %d", &N, &M);
		for (int i = 1; i <= M; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			for (int j = 1; j <= t3; j++) {
				int temp;
				scanf("%d", &temp);
				for (int k = t1 + 1; k <= t2; k++) {
					graph[k][temp] = 1;
				}
			}
		}
		for (int i = 0; i <= 100; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] == 1) {
					left[i].push_back(j);
				}
			}
		}

		for (int i = 0; i <= 100; i++) {
			for (int j = 1; j <= N; j++) {
				check[j] = false;
			}
			if (dfs(i)) {
				ans++;
			}
			if (ans == N) {
				printf("%d\n", i);
				break;
			}
			if (i == 100) {
				printf("-1\n");
			}
		}
	}

}

void init(void) {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			graph[i][j] = 0;
		}
		left[i].clear();
		match[i] = 0;
	}
	ans = 0;
}

bool dfs(int ind) {
	for (int i = 0; i < left[ind].size(); i++) {
		if (check[left[ind][i]]) {
			continue;
		}
		check[left[ind][i]] = true;

		if (match[left[ind][i]] == 0) {
			match[left[ind][i]] = ind;
			return true;
		}
		else {
			if (dfs(match[left[ind][i]])) {
				match[left[ind][i]] = ind;
				return true;
			}
		}
	}
	return false;
}