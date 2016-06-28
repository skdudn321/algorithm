#include<stdio.h>

int cal[2];

int main(void){
	int N;
	int temp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		cal[0] += ((temp / 30) + 1) * 10;
		cal[1] += ((temp / 60) + 1) * 15;
	}

	if (cal[0] < cal[1]){
		printf("Y %d", cal[0]);
	}
	else if (cal[0] > cal[1]){
		printf("M %d", cal[1]);
	}
	else{
		printf("Y M %d", cal[0]);
	}
}