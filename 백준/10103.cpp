#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int game_1 = 100, game_2 = 100;

int main(void){
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		if (temp1 > temp2){
			game_2 -= temp1;
		}
		else if (temp1 < temp2){
			game_1 -= temp2;
		}
	}

	printf("%d\n%d", game_1, game_2);
}