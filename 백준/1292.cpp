#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int sum[1001];

int main(void){
	int N, M, ind = 1;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= 100; i++){
		for (int j = 1; j <= i; j++){
			sum[ind] = sum[ind - 1] + i;
			ind++;
			if (ind > M){
				break;
			}
		}
		if (ind > M){
			break;
		}
	}

	printf("%d", sum[M] - sum[N - 1]);
}