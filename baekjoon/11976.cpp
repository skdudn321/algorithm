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

int main(void) {
	int t[9];
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &t[i]);
	}
	int ans1, ans2, ans3;
	ans3 = t[8] - t[7];
	t[5] -= ans3;
	ans2 = t[6] - t[5];
	t[3] -= ans2;
	ans1 = t[4] - t[3];
	printf("%d\n%d\n%d", ans1, ans2, ans3);
}