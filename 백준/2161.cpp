#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<functional>
#include<math.h>

using namespace std;

deque<int> dq;

int ans;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = N; i >= 1; i--) {
		dq.push_front(i);
	}

	while (1) {
		printf("%d ", dq.front());
		dq.pop_front();
		if (dq.empty()) {
			break;
		}
		dq.push_back(dq.front());
		dq.pop_front();
	}
}