#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

lli ans;
int N, K;

lli yak(lli down, lli mod, lli cou);

int main(void) {
	scanf("%d %d", &N, &K);
	lli up = 1;
	lli down = 1;
	lli mod = 1000000007LL;
	for (int i = 1; i <= N; i++) {
		up *= i;
		up %= mod;
	}
	for (int i = 1; i <= K; i++) {
		down *= i;
		down %= mod;
	}
	for (int i = 1; i <= N - K; i++) {
		down *= i;
		down %= mod;
	}

	down = yak(down, mod, mod - 2);
	ans = up * down % mod;
	printf("%lld", ans);
}

lli yak(lli down, lli mod, lli cou) {
	lli ret = 1;

	while (cou != 0) {
		if (cou % 2 == 0) {
			down = down * down;
			down %= mod;
			cou /= 2;
		}
		else {
			ret *= down;
			ret %= mod;
			cou--;
		}
	}

	return ret;
}