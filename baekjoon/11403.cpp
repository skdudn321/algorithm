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

int graph[101][101];
int N;
bool check[101];

void dfs(int start, int num);

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			scanf("%d", &temp);
			graph[i][j] = temp;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			check[j] = false;
		}
		dfs(i, i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

void dfs(int start, int num) {
	check[num] = true;

	for (int i = 1; i <= N; i++) {
		if (graph[num][i] == 1) {
			graph[start][i] = 1;
			if (!check[i]) {
				dfs(start, i);
			}
		}
	}
}