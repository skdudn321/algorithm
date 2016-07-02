#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int sum;
int bae[100000];
int ind;

int main(void){

	int num;

	while (1){
		scanf("%d", &num);
		if (num == -1){
			return 0;
		}
		int i;
		sum = 0;
		ind = 0;
		for (i = 1; i < num ; i++){
			if (num % i == 0){
				sum += i;
				bae[ind++] = i;
			}
		}
		if (sum == num){
			printf("%d = 1 ", num);
			for (int i = 1; i < ind; i++){
				printf("+ %d ", bae[i]);
			}
			printf("\n");
		}
		else{
			printf("%d is NOT perfect.\n", num);
		}
	}
}