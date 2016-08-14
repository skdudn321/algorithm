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

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		t3 -= 1;
		printf("%d%02d\n", (t3 % t1) + 1, (t3 / t1) + 1);
	}
}