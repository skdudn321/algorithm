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
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		if (i % 2 == 1){
			for (int j = 1; j <= N; j++){
				printf("* ");
			}
			printf("\n");
		}
		else{
			for (int j = 1; j <= N; j++){
				printf(" *");
			}
			printf("\n");
		}
	}
}