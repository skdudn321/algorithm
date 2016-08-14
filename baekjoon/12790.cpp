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

int ans;

int solve(void);

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		printf("%d\n", solve());
	}
}

int solve(void) {
	int t[9];
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &t[i]);
	}
	for (int i = 1; i <= 4; i++) {
		t[i] += t[i + 4];
	}
	if (t[1] < 1) {
		t[1] = 1;
	}
	if (t[2] < 1) {
		t[2] = 1;
	}
	if (t[3] < 0) {
		t[3] = 0;
	}

	return t[1] + 5 * t[2] + 2 * t[3] + 2 * t[4];
}