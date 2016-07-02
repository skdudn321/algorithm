#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int main(void){
	int N, count = 0, high;
	scanf("%d", &N);
	high = N * N;

	while (true){
		for (int i = 1; i <= (N + 1) / 2; i++){
			printf("* ");
			count++;
			if (count == high){
				return 0;
			}
		}
		printf("\n");
		for (int i = 1; i <= N / 2; i++){
			printf(" *");
			count++;
			if (count == high){
				return 0;
			}
		}
		printf("\n");
	}
}