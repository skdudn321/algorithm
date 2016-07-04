#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;
int num[101];
long long int dp_table[101][21];

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}

	dp_table[1][num[1]] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 0; j + num[i] <= 20; j++) {
			dp_table[i][j] += dp_table[i - 1][j + num[i]];
		}
		for (int j = 20; j - num[i] >= 0; j--) {
			dp_table[i][j] += dp_table[i - 1][j - num[i]];
		}
	}

	printf("%lld", dp_table[N - 1][num[N]]);
}