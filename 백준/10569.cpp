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
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		int sum, a, b;
		scanf("%d %d", &a, &b);
		sum = b - a + 2;
		printf("%d\n", sum);
	}
}