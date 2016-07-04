#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

int gedan[500];
int dp_table[500];

int main(void){
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &gedan[i]);
	}

	dp_table[1] = gedan[1];
	dp_table[2] = gedan[1] + gedan[2];
	
	for (int i = 3; i <= N; i++){
		int temp1 = gedan[i] + gedan[i - 1] + dp_table[i - 3];
		int temp2 = gedan[i] + dp_table[i - 2];

		dp_table[i] = temp1 > temp2 ? temp1 : temp2;
	}

	printf("%d", dp_table[N]);
}