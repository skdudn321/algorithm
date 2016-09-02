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
int table[301][301];
vector<int> left[301];
int matching[301];
bool check[301];

bool dfs(int ind);

int main(void) {
	int R, C, N;
	scanf("%d %d %d", &R, &C, &N);
	for (int i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		table[t1][t2] = 1;
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (table[i][j] == 0) {
				left[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			check[j] = false;
		}
		if (dfs(i)) {
			ans++;
		}
	}
	printf("%d", ans);
}

bool dfs(int ind) {
	for (int i = 0; i < left[ind].size(); i++) {
		if (check[left[ind][i]]) {
			continue;
		}
		check[left[ind][i]] = true;
		if (matching[left[ind][i]] == 0) {
			matching[left[ind][i]] = ind;
			return true;
		}
		else {
			if (dfs(matching[left[ind][i]])) {
				matching[left[ind][i]] = ind;
				return true;
			}
		}
	}

	return false;
}