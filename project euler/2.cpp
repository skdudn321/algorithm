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
	int first = 1;
	int second = 1;
	int temp;

	while (second < 4000000) {
		temp = second;
		second += first;
		first = temp;
		if (second % 2 == 0) {
			ans += second;
		}
	}

	printf("%d", ans);
}