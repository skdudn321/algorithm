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

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> jj;

int ans;
priority_queue< jj, vector<jj>, greater<jj> > pq;

int main(void) {
	int n, s;
	scanf("%d %d", &n, &s);
	s = n - s;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		pq.push(jj(0, ii(i, temp)));
	}

	while (s--) {
		jj temp = pq.top();
		pq.pop();
		ans = temp.second.first;
		temp.first += temp.second.second;
		pq.push(temp);
	}
	printf("%d", ans);
}