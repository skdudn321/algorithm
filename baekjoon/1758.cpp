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

long long int ans;
priority_queue<int> pq;

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		pq.push(temp);
	}
	for (int i = 1; i <= N; i++) {
		if (pq.top() - i + 1 <= 0) {
			break;
		}
		ans += (pq.top() - i + 1);
		pq.pop();
	}

	printf("%lld", ans);
}