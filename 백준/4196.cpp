#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

int ans;
int check[100001];
int cc[100001];
int group[100002];
vector<int> ve[100001];
int g_num;

void recursion(int n);
void recursion2(int n);

int main(void) {

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		ans = 0;
		g_num = 0;
		for (int j = 1; j <= 100000; j++) {
			check[j] = 0;
			cc[j] = 0;
			group[j] = 0;
			ve[j].clear();
		}
		group[100001] = 0;
		int N, M;
		scanf("%d %d", &N, &M);
		for (int j = 1; j <= M; j++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			ve[t1].push_back(t2);
			cc[t2] = 1;
		}

		for (int j = 1; j <= N; j++) {
			if (cc[j] == 0) {
				ans++;
				recursion(j);
			}
		}

		for (int j = 1; j <= N; j++) {
			if (check[j] == 0) {
				g_num++;
				group[g_num] = 1;
				recursion2(j);
			}
		}

		for (int j = 1; j <= g_num; j++){
			if (group[j]){
				ans++;
			}
		}

		printf("%d\n", ans);
	}
}

void recursion(int n) {
	check[n] = 100001;
	for (int i = 0; i < ve[n].size(); i++) {
		if (check[ve[n][i]] == 0) {
			recursion(ve[n][i]);
		}
	}
}

void recursion2(int n) {
	check[n] = g_num;
	for (int i = 0; i < ve[n].size(); i++) {
		if (check[ve[n][i]] != g_num) {
			group[check[ve[n][i]]] = 0;
			recursion2(ve[n][i]);
		}
	}
}