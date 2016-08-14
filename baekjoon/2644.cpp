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
int graph[101][101];
int st, fi;
bool check[101];
queue<ii> qu;

int main(void) {
	int N;
	scanf("%d %d %d", &N, &st, &fi);
	int M;
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1][t2] = 1;
		graph[t2][t1] = 1;
	}
	qu.push(ii(st, 0));
	while (!qu.empty()) {
		ii temp = qu.front();
		qu.pop();
		if (check[temp.first]) {
			continue;
		}
		check[temp.first] = true;
		if (temp.first == fi) {
			printf("%d", temp.second);
			return 0;
		}
		for (int i = 1; i <= N; i++) {
			if (graph[temp.first][i] && !check[i]) {
				qu.push(ii(i, temp.second + 1));
			}
		}
	}
	printf("-1");
}