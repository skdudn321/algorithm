#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

typedef pair<int, int> ii;

ii water[10010];
int ans;
int N, L;

int recursion(int start, int finish);

int main(void) {
	int i, j, k;
	int a, b;
	int temp;

	scanf("%d %d", &N, &L);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		water[i] = ii(a, b);
	}

	sort(water, water + N);

	temp = -1;
	for (int i = 0; i < N; i++) {
		if (temp + 1 >= water[i].second) {
			continue;
		}
		temp = recursion(max(temp + 1, water[i].first), water[i].second);
	}

	printf("%d", ans);
}

int recursion(int start, int finish) {
	int r_value;
	int temp = 0;
	temp += (finish - start - 1) / L;
	temp++;
	ans += temp;
	r_value = start + temp * L - 1;
	return r_value;
}