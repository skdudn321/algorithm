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
int can_go[251][251];
int value[251][251];
int real_go[251][251];
vector<int> graph[251];

void init(void);
bool find_path(void);

int main(void) {
	while (1) {
		scanf("%d %d", &N, &M);
		init();
		if (N == 0 && M == 0) {
			break;
		}
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			can_go[i + 100][250] = temp;
			graph[i + 100].push_back(250);
		}
		for (int i = 1; i <= M; i++) {
			int t1, t2, t3, t4, t5;
			scanf("%d %d %d %d %d", &t1, &t2, &t3, &t4, &t5);
			graph[0].push_back(i);
			can_go[0][i] = 1;
			can_go[i][t2 + 100] = 1;
			can_go[i][t3 + 100] = 1;
			can_go[i][t4 + 100] = 1;
			can_go[i][t5 + 100] = 1;
			graph[i].push_back(t2 + 100);
			graph[i].push_back(t3 + 100);
			graph[i].push_back(t4 + 100);
			graph[i].push_back(t5 + 100);
			value[i][t2 + 100] = t1 * 4;
			value[i][t3 + 100] = t1 * 4 - 1;
			value[i][t4 + 100] = t1 * 4 - 2;
			value[i][t5 + 100] = t1 * 4 - 3;
			value[t2 + 100][i] = -(t1 * 4);
			value[t3 + 100][i] = -(t1 * 4 - 1);
			value[t4 + 100][i] = -(t1 * 4 - 2);
			value[t5 + 100][i] = -(t1 * 4 - 3);
			graph[t2 + 100].push_back(i);
			graph[t3 + 100].push_back(i);
			graph[t4 + 100].push_back(i);
			graph[t5 + 100].push_back(i);
		}

		while (find_path());

		printf("%d\n", -ans);
	}
}

void init(void) {
	ans = 0;
	for (int i = 0; i <= 250; i++) {
		for (int j = 0; j <= 250; j++) {
			can_go[i][j] = 0;
			real_go[i][j] = 0;
			value[i][j] = 0;
		}
		graph[i].clear();
	}
}

bool find_path(void) {
	int m[251];
	int parent[251];
	bool check[251];
	m[0] = 0;
	check[0] = true;
	parent[0] = 0;
	for (int i = 1; i <= 250; i++) {
		m[i] = 1000000000;
		check[i] = false;
		parent[i] = -1;
	}
	queue<int> cur;
	cur.push(0);
	
	bool change = true;
	while (!cur.empty()) {
		int i = cur.front();
		cur.pop();
		for (int k = 0; k < graph[i].size(); k++) {
			int j = graph[i][k];
			if (can_go[i][j] - real_go[i][j] <= 0) {
				continue;
			}
			if (m[j] > m[i] - value[i][j]) {
				m[j] = m[i] - value[i][j];
				parent[j] = i;
				cur.push(j);
				change = true;
			}
		}
	}
	if (m[250] > 900000000) {
		return false;
	}
	else {
		ans += m[250];
		int ind = 250;
		while (parent[ind] != ind) {
			real_go[parent[ind]][ind] = 1;
			real_go[ind][parent[ind]] = -1;
			ind = parent[ind];
		}
		return true;
	}
}