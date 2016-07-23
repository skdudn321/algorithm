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

bool sosu[1000001];
int ans;

bool check(int N);

int main(void) {
	for (int i = 2; i <= 1000000; i++) {
		sosu[i] = true;
	}

	for (int i = 2; i <= 1000000; i++) {
		if (sosu[i]) {
			for (int j = 2; i * j <= 1000000; j++) {
				sosu[i * j] = false;
			}
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (sosu[i] && check(i)) {
			ans++;
		}
	}

	printf("%d", ans);
}

bool check(int N) {
	int mod = 10;
	int cou = 1;
	while (N / mod != 0) {
		mod *= 10;
		cou++;
	}

	for (int i = 1; i <= cou; i++) {
		if (!sosu[N]) {
			return false;
		}
		N = ((N * 10) / mod) + ((N * 10) % mod);
	}

	return true;
}