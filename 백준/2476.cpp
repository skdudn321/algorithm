#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int score;

int main(void){
	int N;
	int a, b, c;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && b == c){
			score = max(score, 10000 + a * 1000);
		}
		else if (a == b){
			score = max(score, 1000 + a * 100);
		}
		else if (b == c){
			score = max(score, 1000 + b * 100);
		}
		else if (a == c){
			score = max(score, 1000 + a * 100);
		}
		else{
			score = max(score, max(a * 100, max(b * 100, c * 100)));
		}
	}

	printf("%d", score);
}