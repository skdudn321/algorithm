#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

priority_queue<int> pq;

int main(void) {
	long long int ans = 0;
	int N, K;
	scanf("%d %d", &N, &K);
	int fi;
	scanf("%d", &fi);
	for (int i = 1; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		pq.push(temp - fi);
		ans += temp - fi;
		fi = temp;
	}
	for (int i = 1; i < K; i++) {
		ans -= pq.top();
		pq.pop();
	}
	printf("%lld", ans);
}