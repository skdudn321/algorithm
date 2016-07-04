#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans = 0;

int main(void) {
	int a, b;

	for (int i = 1; i <= 4; i++) {
		scanf("%d %d", &a, &b);
		ans = max(ans, ans + b - a);
	}
	printf("%d", ans);
}