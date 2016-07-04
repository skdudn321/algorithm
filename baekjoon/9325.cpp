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
	int N, T;
	int money;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &money, &N);
		for (int j = 1; j <= N; j++){
			int a, b;
			scanf("%d %d", &a, &b);
			money += a* b;
		}
		printf("%d\n", money);
	}
}