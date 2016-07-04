#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

unsigned long long int pibo[100];

unsigned long long int recursion(int N);

int main(void){
	int N;

	scanf("%d", &N);

	pibo[1] = 1;

	printf("%lld", recursion(N));
}

unsigned long long int recursion(int N){
	if (pibo[N] != 0){
		return pibo[N];
	}
	if (N == 0){
		return 0;
	}

	pibo[N] = recursion(N - 1) + recursion(N - 2);
	return pibo[N];
}