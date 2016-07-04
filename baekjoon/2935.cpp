#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

char A[110];
char B[110];
char temp;

int main(void){
	int length1, length2;
	scanf("%s\n%c\n%s", A, &temp, B);
	length1 = strlen(A);
	length2 = strlen(B);

	if (temp == '*'){
		printf("1");
		for (int i = length1 + length2 - 2; i >= 1; i--){
			printf("0");
		}
	}
	else{
		for (int i = max(length1, length2); i >= 1; i--){
			if (i == length1 || i == length2){
				if (length1 == length2){
					printf("2");
				}
				else{
					printf("1");
				}
			}
			else{
				printf("0");
			}
		}
	}
}