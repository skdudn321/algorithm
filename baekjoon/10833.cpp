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

int ans;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		ans += t2 % t1;
	}

	printf("%d", ans);
}