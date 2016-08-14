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

bool check[1000001];
priority_queue<ii> pq;
priority_queue< ii, vector<ii>, greater<ii> > pq2;

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int N;
		int ind = 1;
		while (!pq.empty()) {
			pq.pop();
		}
		while (!pq2.empty()) {
			pq2.pop();
		}
		scanf("%d\n", &N);
		for (int i = 1; i <= N; i++) {
			char t1;
			int t2;
			scanf("%c %d\n", &t1, &t2);
			if (t1 == 'I') {
				pq.push(ii(t2, ind));
				pq2.push(ii(t2, ind));
				check[ind++] = true;
			}
			else {
				if (t2 == 1) {
					while (!pq.empty() && !check[pq.top().second]) {
						pq.pop();
					}
					if (pq.empty()) {
						continue;
					}
					check[pq.top().second] = false;
					pq.pop();
				}
				else {
					while (!pq2.empty() && !check[pq2.top().second]) {
						pq2.pop();
					}
					if (pq2.empty()) {
						continue;
					}
					check[pq2.top().second] = false;
					pq2.pop();
				}
			}
		}
		while (!pq.empty() && !check[pq.top().second]) {
			pq.pop();
		}
		while (!pq2.empty() && !check[pq2.top().second]) {
			pq2.pop();
		}
		if (pq.empty()) {
			printf("EMPTY\n");
		}
		else {
			printf("%d %d\n", pq.top().first, pq2.top().first);
		}
	}
}