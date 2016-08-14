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
int N, K;
bool check[100001];

void bfs();

int main(void) {
	scanf("%d %d", &N, &K);
	bfs();
	printf("%d", ans);
}

void bfs() {
	queue<ii> qu;

	qu.push(ii(N, 0));

	while (!qu.empty()) {
		int temp = qu.front().first;
		int cou = qu.front().second;
		qu.pop();

		if (check[temp]) {
			continue;
		}
		check[temp] = true;
		if (temp == K) {
			ans = cou;
			return;
		}

		if (temp > 0 && !check[temp - 1]) {
			qu.push(ii(temp - 1, cou + 1));
		}
		if (temp < 100000 && !check[temp + 1]) {
			qu.push(ii(temp + 1, cou + 1));
		}
		if (temp <= 50000 && !check[temp * 2]) {
			qu.push(ii(temp * 2, cou + 1));
		}
	}
}