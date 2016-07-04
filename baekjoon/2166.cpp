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

double ans;

double dot[2][10002];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%lf %lf", &dot[0][i], &dot[1][i]);
	}
	dot[0][N + 1] = dot[0][1];
	dot[1][N + 1] = dot[1][1];

	for (int i = 1; i <= N; i++) {
		ans += dot[0][i] * dot[1][i + 1];
		ans -= dot[1][i] * dot[0][i + 1];
	}

	if (ans < 0) {
		ans = -ans;
	}

	printf("%.1lf", ans / 2);
}