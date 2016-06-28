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
	int T;
	int x1, y1, x2, y2;
	int N;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &N);
		ans = 0;
		for (int j = 1; j <= N; j++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if ((t1 - x1) * (t1 - x1) + (t2 - y1) * (t2 - y1) > t3 * t3 && (t1 - x2) * (t1 - x2) + (t2 - y2) * (t2 - y2) < t3 * t3) {
				ans++;
			}
			if ((t1 - x1) * (t1 - x1) + (t2 - y1) * (t2 - y1) < t3 * t3 && (t1 - x2) * (t1 - x2) + (t2 - y2) * (t2 - y2) > t3 * t3) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}