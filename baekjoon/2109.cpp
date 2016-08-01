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

int N;
int ans;
int fin;
vector<int> ve[10001];
priority_queue<int> pq;

int main(void) {
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		fin = max(fin, t2);
		ve[t2].push_back(t1);
	}

	for (int i = fin; i >= 1; i--) {
		for (int j = 0; j < ve[i].size(); j++) {
			pq.push(ve[i][j]);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	printf("%d", ans);
}