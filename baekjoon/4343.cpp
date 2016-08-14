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
typedef pair<double, ii> di;

int group[501];

void solve(void);
double distance(int x1, int y1, int x2, int y2);
int find(int x);
void merge(int x, int y);

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve();
	}
}

void solve(void) {
	int N, M;
	int x[501], y[501];
	double ans;
	scanf("%d %d", &N, &M);
	priority_queue< di, vector<di>, greater<di> > pq;
	int cou = M;
	for (int i = 1; i <= M; i++) {
		group[i] = i;
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 1; i <= M; i++) {
		for (int j = i + 1; j <= M; j++) {
			pq.push(di(sqrt(distance(x[i], y[i], x[j], y[j])), ii(i, j)));
		}
	}

	while (cou > N) {
		ans = pq.top().first;
		if (find(pq.top().second.first) != find(pq.top().second.second)) {
			merge(pq.top().second.first, pq.top().second.second);
			cou--;
		}
		pq.pop();
	}

	printf("%.2lf\n", ans);
}

double distance(int x1, int y1, int x2, int y2) {
	int ret = (x2 - x1) * (x2 - x1);
	ret += (y2 - y1) * (y2 - y1);
	return (double)ret;
}

int find(int x) {
	while (x != group[x]) {
		x = group[x];
	}
	return x;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	group[x] = y;
}