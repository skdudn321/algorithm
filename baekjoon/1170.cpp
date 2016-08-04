#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int ans;

bool check[201];
bool graph[201][201];
int N, M;
bool group[201];
stack<int> st;

bool recursion(int num, int parent);

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1][t2] = true;
		graph[t2][t1] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			st.push(i);
			if (recursion(i, 0)) {
				ans++;
			}
			while (!st.empty()) {
				st.pop();
			}
		}
	}

	printf("%d", ans);
}

bool recursion(int num, int parent) {
	check[num] = true;
	bool ret = true;

	for (int i = 1; i <= N; i++) {
		if (i != parent && graph[num][i]) {
			if (check[i]) {
				stack<int> temp;
				while (st.top() != i) {
					temp.push(st.top());
					st.pop();
				}
				temp.push(st.top());
				st.pop();
				while (!temp.empty()) {
					if (group[temp.top()]) {
						ret = false;
					}
					group[temp.top()] = true;
					st.push(temp.top());
					temp.pop();
				}
				graph[i][num] = false;
				graph[num][i] = false;
			}
			else {
				st.push(i);
				ret &= recursion(i, num);
				st.pop();
			}
		}
	}

	return ret;
}