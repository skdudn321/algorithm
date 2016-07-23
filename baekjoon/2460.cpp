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
	int down, up;
	int cur = 0;
	for (int i = 1; i <= 10; i++) {
		scanf("%d %d", &down, &up);
		cur = cur + up - down;
		ans = max(cur, ans);
	}
	printf("%d", ans);
}