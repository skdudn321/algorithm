#include<stdio.h>

void recursion(int num);
int answer;

int main(void){
	int i, N, temp;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%d", &temp);
		answer = 0;
		recursion(temp);
		printf("%d", answer);
		if (i != N){
			printf("\n");
		}
	}
}

void recursion(int num){
	if (num == 0){
		answer++;
	}
	else if(num > 0){
		recursion(num - 1);
		recursion(num - 2);
		recursion(num - 3);
	}
}