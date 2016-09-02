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

int ans;
lli table[72];

lli gcd(lli t1, lli t2);

int main(void) {
	int T;
	table[1] = 1;
	for (int i = 2; i <= 71; i++) {
		table[i] = table[i - 1] + table[i - 2];
	}
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int X, Y, N, M;
		scanf("%d %d %d %d", &X, &N, &Y, &M);
		lli t1, t2;
		t1 = table[N + 1] * X + Y;
		t2 = table[N] * X;
		printf("Case %d: %lld\n", C, gcd(t1, t2));
	}
}

lli gcd(lli t1, lli t2) {
	while (t2 != 0) {
		lli temp = t1 % t2;
		t1 = t2;
		t2 = temp;
	}

	return t1;
}