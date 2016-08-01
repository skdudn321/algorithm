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
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	a = a - b;
	if (a < 0) {
		printf("%lld", -a);
	}
	else {
		printf("%lld", a);
	}
}