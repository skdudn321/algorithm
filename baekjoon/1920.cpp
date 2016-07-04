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

int ans;
int pt[100001];

priority_queue<int, vector<int>, greater<int> > A;
priority_queue<ii, vector<ii>, greater<ii> > B;

int main(void) {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		A.push(t);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int t;
		scanf("%d", &t);
		B.push(ii(t, i));
	}

	while (!A.empty() && !B.empty()) {
		int a = A.top();
		int b = B.top().first;

		int check = min(a, b);

		if (check == a && check == b) {
			pt[B.top().second] = 1;
			B.pop();
		}
		else if (check == a) {
			A.pop();
		}
		else {
			B.pop();
		}
	}

	for (int i = 1; i <= M; i++) {
		printf("%d\n", pt[i]);
	}
}