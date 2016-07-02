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
	int T;
	int N, sum = 0;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++){
		scanf("%d", &N);
		sum = 0;
		for (int j = 1; j <= N; j++){
			int temp;
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
}