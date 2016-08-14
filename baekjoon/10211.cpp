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
int cur;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int N;
		scanf("%d", &N);
		ans = -100000;
		cur = 0;
		for (int i = 1; i <= N; i++) {
			int temp;
			scanf("%d", &temp);
			cur += temp;
			ans = max(ans, cur);
			if (cur < 0) {
				cur = 0;
			}
		}
		printf("%d\n", ans);
	}
}