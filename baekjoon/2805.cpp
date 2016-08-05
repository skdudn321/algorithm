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
lli table[1000001];
int N, M;
lli right, left;

bool search(lli ind);

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &table[i]);
		right = max(right, table[i]);
	}

	while (left != right) {
		lli mid = ((lli)right + left + 1) / 2;
		
		if (search(mid)) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%lld", right);
}

bool search(lli ind) {
	lli ret = 0;
	for (int i = 1; i <= N; i++) {
		if (table[i] > ind) {
			ret += table[i] - ind;
		}
	}
	if (ret >= M) {
		return true;
	}
	return false;
}