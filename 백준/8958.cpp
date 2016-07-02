#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int N;
char str[100];
int score, sum;

int main(void){
	int length;

	scanf("%d\n", &N);

	for (int i = 0; i < N; i++){
		scanf("%s\n", str);
		length = strlen(str);
		score = 0;
		sum = 0;
		for (int j = 0; j < length; j++){
			if (str[j] == 'O'){
				sum += 1;
				score += sum;
			}
			else{
				sum = 0;
			}
		}
		printf("%d\n", score);
	}
}