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
	int N = 0;
	int sum = 0;
	int small = 9990;

	for (int i = 0; i < 7; i++){
		int temp = 0;
		scanf("%d", &temp);
		if (temp % 2 == 1){
			sum += temp;
			N++;
			small = min(small, temp);
		}
	}

	if (N == 0){
		printf("-1");
	}
	else{
		printf("%d %d", sum, small);
	}
}