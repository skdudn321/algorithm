#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<functional>
#include<math.h>

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

lli ans = 200000000000;
int ans2 = 0;
lli left[100001];
lli right[100001];
lli mid[100001];
int N;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &mid[i]);
	}
	for (int i = 1; i < N; i++) {
		scanf("%lld", &left[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		scanf("%lld", &right[i]);
	}

	for (int i = 1; i < N; i++) {
		left[i] += left[i - 1];
	}
	for (int i = N - 2; i >= 0; i--) {
		right[i] += right[i + 1];
	}
	for (int i = 0; i < N; i++) {
		if (ans > left[i] + right[i] + mid[i]) {
			ans = left[i] + right[i] + mid[i];
			ans2 = i;
		}
	}

	printf("%d %lld", ans2 + 1, ans);
}