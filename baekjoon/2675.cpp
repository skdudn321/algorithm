#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

char str[30];

int main(void){
	int N;


	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int time;
		scanf("%d %s\n", &time, str);
		int length = strlen(str);
		for (int j = 0; j < length; j++){
			for (int k = 1; k <= time; k++){
				printf("%c", str[j]);
			}
		}
		printf("\n");
	}
}