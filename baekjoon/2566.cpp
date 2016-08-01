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
int x, y;

int main(void) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int temp;
			scanf("%d", &temp);
			if (ans < temp) {
				x = i;
				y = j;
				ans = temp;
			}
		}
	}
	printf("%d\n%d %d", ans, x, y);
}