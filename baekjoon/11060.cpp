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

priority_queue< int, vector<int>, greater<int> > s_pq; // 오름차순
priority_queue< int > b_pq; // 내림차순

int table[1001];

int main(void) {

	int N;
	int cur = 1;
	int cou = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
	}

	b_pq.push(table[1] + 1);
	while (cur < N) {
		int temp = b_pq.top();
		if (temp == cur) {
			printf("-1");
			return 0;
		}
		for (int i = cur + 1; i <= temp; i++) {
			b_pq.push(i + table[i]);
		}
		cur = temp;
		cou++;
	}
	printf("%d", cou);
}