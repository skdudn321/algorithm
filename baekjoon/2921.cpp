#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int main(void){
	int N, sum = 0;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= i; j++){
			sum += i + j;
		}
	}
	printf("%d", sum);
}