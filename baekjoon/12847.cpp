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

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

lli ans;
lli cur;
int table[100001];

int main(void) {
	int N, T;
	scanf("%d %d", &N, &T);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
	}
	for (int i = 1; i <= T; i++) {
		cur += table[i];
	}
	ans = cur;
	for (int i = T + 1; i <= N; i++) {
		cur = cur - table[i - T] + table[i];
		ans = max(ans, cur);
	}
	printf("%lld", ans);
}