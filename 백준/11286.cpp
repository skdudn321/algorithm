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

typedef pair<int, int> ii;

priority_queue<int, vector<int>, greater<int> > pq[2];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 0) {
			if (pq[0].empty() && pq[1].empty()) {
				printf("0\n");
			}
			else if(pq[0].empty()){
				printf("-%d\n", pq[1].top());
				pq[1].pop();
			}
			else if (pq[1].empty()) {
				printf("%d\n", pq[0].top());
				pq[0].pop();
			}
			else {
				if (pq[0].top() < pq[1].top()) {
					printf("%d\n", pq[0].top());
					pq[0].pop();
				}
				else {
					printf("-%d\n", pq[1].top());
					pq[1].pop();
				}
			}
		}
		else {
			if (temp < 0) {
				pq[1].push(temp * -1);
			}
			else {
				pq[0].push(temp);
			}
		}
	}
}