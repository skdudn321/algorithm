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

bool ans = true;
int N, M;
vector<int> graph[100001];
bool group[100001];
int check[100001];

stack<int> st;

void cactus(int num, int parent);
bool make_group(int start, int fin);

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	cactus(1, 0);
	if (ans) {
		printf("Cactus");
	}
	else {
		printf("Not cactus");
	}
}

void cactus(int num, int parent) {
	check[num] = -1;
	st.push(num);
	for (int i = 0; i < graph[num].size(); i++) {
		if (graph[num][i] == parent) {
			continue;
		}
		if (check[graph[num][i]] == -1) {
			if (!make_group(num, graph[num][i])) {
				ans = false;
			}
		}
		else if (check[graph[num][i]] == 0) {
			cactus(graph[num][i], num);
		}
	}
	st.pop();
	check[num] = 1;
}

bool make_group(int start, int fin) {
	stack<int> temp_st;
	bool ret = true;
	while (temp_st.empty() || temp_st.top() != fin) {
		temp_st.push(st.top());
		if (group[st.top()]) {
			ret = false;
		}
		group[st.top()] = true;
		st.pop();
	}
	while (!temp_st.empty()) {
		st.push(temp_st.top());
		temp_st.pop();
	}

	return ret;
}