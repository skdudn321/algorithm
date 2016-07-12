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

int main(void) {
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= 100; i++) {
		ans1 += i * i;
		ans2 += i;
	}
	ans2 = ans2 * ans2;
	printf("%d", ans2 - ans1);

}