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

#define pivot 1048575

using namespace std;

typedef pair<int, int> ii;

long long int table[2100000];
ii range[2100000];

long long int ans(int index, int a, int b);
void push(int a, int b);

int main(void) {
	range[1] = ii(1, pivot + 1);
	for (int i = 2; i <= 2097151; i++) {
		if (i % 2 == 0) {
			range[i] = ii(range[i/2].first, (range[i/2].second - range[i/2].first) / 2 + range[i/2].first);
		}
		else {
			range[i] = ii(range[i/2].second - (range[i / 2].second - range[i / 2].first) / 2, range[i / 2].second);
		}
	}

	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= Q; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) {
			push(t2, t3);
		}
		else {
			printf("%lld\n", ans(1, t2, t3));
		}
	}
}

void push(int a, int b) {
	int index = pivot + a;
	table[index] += b;
	index /= 2;

	while (index >= 1) {
		table[index] = table[index * 2] + table[index * 2 + 1];
		index /= 2;
	}
}
long long int ans(int index, int a, int b) {
	int mid = (range[index].first + range[index].second) / 2;
	if (a == range[index].first && b == range[index].second) {
		return table[index];
	}
	if (a <= mid && b <= mid) {
		return ans(index * 2, a, b);
	}
	else if (a <= mid && b > mid) {
		return ans(index * 2 , a, mid) + ans(index * 2 + 1, mid + 1, b);
	}
	else {
		return ans(index * 2 + 1, a, b);
	}
}