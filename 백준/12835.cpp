#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

long long int ans_t;
int ans[10];

priority_queue<long long int, vector<long long int>, greater<long long int> > pq[10];

int main(void) {
	int N;
	long long int L;

	scanf("%d %lld\n", &N, &L);

	for (int i = 1; i <= N; i++) {
		char t;
		long long int t1;
		int t2;
		scanf("%c %lld %d\n", &t, &t1, &t2);
		if (t2 == 0) {
			ans_t += (L + t1);
			pq[t - 'A'].push(t1);
		}
		else {
			ans_t += (L - t1);
			ans[t - 'A']++;
		}
	}

	while (!pq[0].empty() || !pq[1].empty() || !pq[2].empty()) {
		long long int V[10];
		for (int i = 0; i <= 2; i++) {
			if (pq[i].empty()) {
				V[i] = 2000000000000LL;
			}
			else {
				V[i] = pq[i].top();
			}
		}

		long long int check = min(V[0], min(V[1], V[2]));

		if (V[0] == check && V[1] == check && V[2] == check) {
			ans[0]++;
			ans[1]++;
			ans[2]++;
			pq[0].pop();
			pq[1].pop();
			pq[2].pop();
		}
		else if (V[0] == check && V[1] == check) {
			ans[0]++;
			ans[1]++;
			pq[0].pop();
			pq[1].pop();
		}
		else if (V[0] == check && V[2] == check) {
			ans[0]++;
			ans[2]++;
			pq[0].pop();
			pq[2].pop();
		}
		else if (V[2] == check && V[1] == check) {
			ans[1]++;
			ans[2]++;
			pq[1].pop();
			pq[2].pop();
		}
		else if (V[0] == check) {
			ans[1]++;
			pq[0].pop();
		}
		else if (V[1] == check) {
			ans[2]++;
			pq[1].pop();
		}
		else {
			ans[0]++;
			pq[2].pop();
		}
	}

	printf("%lld\n%d %d %d", ans_t, ans[0], ans[1], ans[2]);
}