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

long long int ans;
bool sosu[2000001];

int main(void) {
	for (int i = 2; i <= 2000000; i++) {
		sosu[i] = true;
	}
	for (int i = 2; i <= 2000000; i++) {
		if (sosu[i]) {
			ans += i;
			for (int j = 2; i * j <= 2000000; j++) {
				sosu[i * j] = false;
			}
		}
	}
	printf("%lld", ans);
}