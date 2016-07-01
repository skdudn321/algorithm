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
	int N, cur = 0, sum = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		int temp;
		scanf("%d", &temp);
		if (temp == 0){
			cur = 0;
		}
		if (temp == 1){
			cur++;
			sum += cur;
		}
	}

	printf("%d", sum);
}