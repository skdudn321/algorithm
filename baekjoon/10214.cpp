#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int Y, K;

int main(void){
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		Y = 0;
		K = 0;
		for (int j = 0; j < 9; j++){
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			Y += temp1;
			K += temp2;
		}
		if (Y > K){
			printf("Yonsei\n");
		}
		else if (K > Y){
			printf("Korea\n");
		}
		else{
			printf("Draw\n");
		}
	}
}