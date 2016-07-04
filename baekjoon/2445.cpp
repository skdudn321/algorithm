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
		for (int j = 1; j <= N; j++){
			if (i >= j){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		for (int j = 1; j <= N; j++){
			if (N - i >= j){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (N - i + 1 >= j){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		for (int j = 1; j <= N; j++){
			if (i > j){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
}