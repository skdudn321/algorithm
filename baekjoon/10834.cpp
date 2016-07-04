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

double a = 1;
int ans;
int dir;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t3 == 1) {
			dir = (dir + 1) % 2;
		}
		a *= t2;
		a /= t1;
	}

	printf("%d %.0lf", dir, a);
}