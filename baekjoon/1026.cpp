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

int A[51];
int B[51];

int main(void) {
	int N;
	int i, j, k;
	int sum = 0;

	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	sort(A, A + N);
	sort(B, B + N, greater<int>());

	for (i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}

	printf("%d", sum);
}