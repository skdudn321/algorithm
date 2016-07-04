#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<functional>
#include<math.h>

using namespace std;

int ans;

int main(void) {
	int N;
	int t;
	scanf("%d", &N);

	if (N == 1) {
		printf("1");
		return 0;
	}
	t = 2;
	while (t < N) {
		t *= 2;
	}

	t = t - 2 * (t - N);
	printf("%d", t);
}