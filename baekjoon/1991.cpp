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
ii graph[30];
int N;

void dfs1(int num);
void dfs2(int num);
void dfs3(int num);

int main(void) {
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) {
		char t1, t2, t3;
		scanf("%c %c %c\n", &t1, &t2, &t3);
		int left, right;
		if (t2 == '.') {
			left = 0;
		}
		else {
			left = t2 - 'A' + 1;
		}

		if (t3 == '.') {
			right = 0;
		}
		else {
			right = t3 - 'A' + 1;
		}

		graph[t1 - 'A' + 1] = ii(left, right);
	}
	dfs1(1);
	printf("\n");
	dfs2(1);
	printf("\n");
	dfs3(1);
}

void dfs1(int num) {
	printf("%c", num + 'A' - 1);
	if (graph[num].first != 0) {
		dfs1(graph[num].first);
	}
	if (graph[num].second != 0) {
		dfs1(graph[num].second);
	}
}

void dfs2(int num) {
	if (graph[num].first != 0) {
		dfs2(graph[num].first);
	}
	printf("%c", num + 'A' - 1);
	if (graph[num].second != 0) {
		dfs2(graph[num].second);
	}
}

void dfs3(int num) {
	if (graph[num].first != 0) {
		dfs3(graph[num].first);
	}
	if (graph[num].second != 0) {
		dfs3(graph[num].second);
	}
	printf("%c", num + 'A' - 1);
}