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

bool sosu[21];
long long int ans = 1;

int main(void) {
	for (int i = 2; i <= 20; i++) {
		sosu[i] = true;
	}
	for (int i = 2; i <= 20; i++) {
		if (sosu[i]) {
			for (int j = 2; i * j <= 20; j++) {
				sosu[i * j] = false;
			}
		}
	}

	for (int i = 2; i <= 20; i++) {
		if (sosu[i]) {
			int temp = i;
			while (temp * i <= 20) {
				temp = temp * i;
			}
			ans *= temp;
		}
	}

	printf("%lld", ans);
}