#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

unsigned long long int fact(int N, int M);

int main(void) {
	int T;
	int N, M;
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		printf("%lld\n", fact(N, M));
	}
}

unsigned long long int fact(int N, int M) {
	int temp = M - N, temp2;
	unsigned long long int ans = 1;

	if (N == 0) {
		return 0;
	}

	if (temp < N) {
		temp2 = N;
		N = temp;
		temp = temp2;
	}
	
	for (int i = M; i > temp; i--) {
		ans *= i;
	}
	for (int i = N; i > 1; i--) {
		ans /= i;
	}

	return ans;
}