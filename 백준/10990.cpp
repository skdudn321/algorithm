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

int ans;

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			printf(" ");
		}
		printf("*");
		for (int j = 1; j < 2 * (i - 1); j++) {
			printf(" ");
		}
		if (i != 1) {
			printf("*");
		}
		printf("\n");
	}
}