#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int N;

int main(void){
	scanf("%d", &N);

	for (int i = 2; i <= N; i++){
		if (N % i == 0){
			N /= i;
			printf("%d\n", i);
			i--;
		}
	}
}