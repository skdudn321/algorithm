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

bool check(int N);

int main(void) {
	for (int i = 1; i <= 1000000; i++) {
		if (check(i)) {
			ans += i;
		}
	}

	printf("%d", ans);
}

bool check(int N) {
	char num[40];
	sprintf(num, "%d", N);
	int temp = 0;
	int mul = 1;
	for (int i = 0; num[i] != 0; i++) {
		temp += (num[i] - '0') * mul;
		mul *= 10;
	}
	if (N != temp) {
		return false;
	}
	int ind = 0;
	while (N != 0) {
		num[ind++] = (N % 2);
		N /= 2;
	}
	for (int i = 0; i < ind; i++) {
		if (num[i] != num[ind - i - 1]) {
			return false;
		}
	}

	return true;
}