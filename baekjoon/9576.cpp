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

/* greedy 전역변수
int ans;
int num_of_book;
vector<int> ve[1001];
priority_queue< int, vector<int>, greater<int> > pq;
*/
int ans;
vector<int> graph[1001];
int group_a[1001], group_b[1001];
bool check[1001];

bool dfs(int num) {
	for (int i = 0; i < graph[num].size(); i++) {
		if (!check[graph[num][i]]) {
			check[graph[num][i]] = true;
			if (group_b[graph[num][i]] == -1 || dfs(group_b[graph[num][i]])) {
				group_a[num] = graph[num][i];
				group_b[graph[num][i]] = num;
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int N, M;
		ans = 0;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= 1000; i++) {
			graph[i].clear();
			group_a[i] = -1;
			group_b[i] = -1;
		}
		for (int i = 1; i <= M; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			for (int j = t1; j <= t2; j++) {
				graph[i].push_back(j);
			}
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				check[j] = false;
			}
			if (dfs(i)) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	/* greedy 소스코드
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		while (!pq.empty()) {
			pq.pop();
		}
		ans = 0;
		num_of_book = 0;
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			ve[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			ve[t1].push_back(t2);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < ve[i].size(); j++) {
				pq.push(ve[i][j]);
			}
			while (!pq.empty()) {
				int temp = pq.top();
				pq.pop();
				if (temp >= i) {
					ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	*/
}