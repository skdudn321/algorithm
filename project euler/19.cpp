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

int table[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(void) {
	int ans = 0;
	int N = 366 % 7;
	for (int i = 1901; i <= 2000; i++) {
		if (N == 0) {
			ans++;
		}
		N = (N + 31) % 7;
		if (N == 0) {
			ans++;
		}
		if (i % 4 == 0 ) {
			N = (N + 29) % 7;
		}
		else {
			N = (N + 28) % 7;
		}
		for (int j = 3; j <= 12; j++) {
			if (N == 0) {
				ans++;
			}
			N = (N + table[j]) % 7;
		}
	}
	printf("%d", ans);
}