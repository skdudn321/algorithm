#include<stdio.h>

bool check(int N);

int main(void){
	int N;

	scanf("%d", &N);

	if (check(N)){
		printf("1");
	}
	else{
		printf("0");
	}
}

bool check(int N){
	while (N >= 1){
		if (N == 1){
			return true;
		}
		if (N % 2 == 0){
			N /= 2;
		}
		else{
			break;
		}
	}
	return false;
}