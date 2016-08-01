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

int ans;
priority_queue< int, vector<int>, greater<int> > pq;

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		pq.push(temp);
	}
	for (int i = N; i >= 1; i--) {
		ans += pq.top() * i;
		pq.pop();
	}

	printf("%d", ans);
}