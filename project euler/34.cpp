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

#define high 1000000

using namespace std;

int ans;

int fact[10];

bool check(int N);

int main(void) {
	fact[0] = 1;
	for (int i = 1; i <= 9; i++) {
		fact[i] = fact[i - 1] * i;
	}

	for (int i = 10; i <= high; i++) {
		if (check(i)) {
			ans += i;
		}
	}
	printf("%d", ans);
}

bool check(int N) {
	int temp = 0;
	int temp2 = N;

	while (temp2 != 0) {
		temp += fact[temp2 % 10];
		temp2 /= 10;
	}

	if (temp == N) {
		return true;
	}
	else {
		return false;
	}
}