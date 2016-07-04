#include<stdio.h>

int A[10];
int B[10];

int main(void){
	int i, count = 0;

	for (i = 0; i < 10; i++){
		scanf("%d", &A[i]);
	}
	for (i = 0; i < 10; i++){
		scanf("%d", &B[i]);
	}

	for (i = 0; i < 10; i++){
		if (A[i] > B[i]){
			count++;
		}
		else if (A[i] < B[i]){
			count--;
		}
	}

	if (count > 0){
		printf("A");
	}
	else if (count < 0){
		printf("B");
	}
	else{
		printf("D");
	}
}