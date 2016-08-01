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
	int T;
	scanf("%d", &T);

	for (int c = 1; c <= T; c++) {
		int N;
		ans = 0;
		while (!pq.empty()) {
			pq.pop();
		}
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			pq.push(temp);
		}
		
		for (int i = 1; i < N; i++) {
			int num1 = pq.top();
			pq.pop();
			int num2 = pq.top();
			pq.pop();
			ans += (num1 + num2);
			pq.push(num1 + num2);
		}

		printf("%d\n", ans);
	}
}