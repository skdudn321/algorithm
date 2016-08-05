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

int N, M;
int table[100001];
bool search(lli ind);

int main(void) {
	scanf("%d %d", &N, &M);
	int temp = 2000000000;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
		temp = min(temp, table[i]);
	}
	lli right = (lli)temp * M;
	lli left = 1;

	while (right != left) {
		lli mid = (right + left) / 2;

		if (search(mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%lld", right);
}

bool search(lli ind) {
	lli ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += (ind / table[i]);
	}

	if (ret >= M) {
		return true;
	}
	return false;
}