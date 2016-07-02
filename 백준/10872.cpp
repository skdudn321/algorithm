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
	int N, sum = 1;

	scanf("%d", &N);
	for (int i = 2; i <= N; i++){
		sum *= i;
	}
	printf("%d", sum);
}