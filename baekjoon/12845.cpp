#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int N;
int ans;
int high;

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		ans += temp;
		high = max(high, temp);
	}
	ans += high * (N - 2);

	printf("%d", ans);
}