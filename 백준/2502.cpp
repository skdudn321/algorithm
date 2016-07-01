#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int dp[35];

int main(void){
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= 34; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int a, b;
	int D, N;
	scanf("%d %d", &D, &N);
	a = dp[D - 3];
	b = dp[D - 2];

	int i = 1;
	while (1){
		if ((N - a * i) % b == 0){
			break;
		}
		i++;
	}

	printf("%d\n%d", i, (N - a * i) / b);
}