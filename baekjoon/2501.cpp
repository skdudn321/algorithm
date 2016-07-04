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
	int N, K, i = 0, j = 1;

	scanf("%d %d", &N, &K);

	while (true){
		if (N % j == 0){
			i++;
		}

		if (j > N){
			printf("0");
			return 0;
		}
		if (i == K){
			printf("%d", j);
			return 0;
		}

		j++;
	}
}