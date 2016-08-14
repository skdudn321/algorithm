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

int ans = -2000000000;
int table[100001];
int hap;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
	}
	for (int i = 1; i <= K; i++) {
		hap += table[i];
	}
	ans = hap;
	for (int i = K + 1; i <= N; i++) {
		hap = hap + table[i] - table[i - K];
		ans = max(ans, hap);
	}
	printf("%d", ans);
}