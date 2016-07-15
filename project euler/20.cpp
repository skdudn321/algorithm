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

int table[301];

int main(void) {
	table[300] = 1;

	for (int i = 1; i <= 100; i++) {
		int up = 0;
		for (int j = 300; j >= 1; j--) {
			table[j] *= i;
			table[j] += up;
			up = table[j] / 10;
			table[j] %= 10;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 300; i++) {
		ans += table[i];
	}
	printf("%d", ans);
}