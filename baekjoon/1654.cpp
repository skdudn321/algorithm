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

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

int ans;
int N, K;
int table[10010];
lli ind;
lli right;
lli left = 1;

bool check_length(int length);

int main(void) {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
		right = max(right, (lli)table[i]);
	}

	while (left != right) {
		ind = (left + right + 1) / 2;
		if (check_length((int)ind)) {
			left = ind;
		}
		else {
			right = ind - 1;
		}
	}

	printf("%lld", right);
}

bool check_length(int length) {
	lli hap = 0;
	for (int i = 1; i <= N; i++) {
		hap += (table[i] / length);
	}
	if (hap >= K) {
		return true;
	}
	else {
		return false;
	}
}