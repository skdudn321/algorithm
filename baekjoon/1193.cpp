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
int N;

int main(void) {
	scanf("%d", &N);
	int i;
	for (i = 1; i < N; i++) {
		N -= i;
	}
	
	if (i % 2 == 0) {
		printf("%d/%d", N, i - N + 1);
	}
	else {
		printf("%d/%d", i - N + 1, N);
	}
}