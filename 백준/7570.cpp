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

int table[1000001];

int main(void) {
	int N, temp, ans = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		table[temp] = table[temp - 1] + 1;
		ans = max(ans, table[temp]);
	}

	printf("%d", N - ans);
}