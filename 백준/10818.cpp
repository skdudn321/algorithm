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
	int maxi = -2000000, mini = 2000000;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		int t;
		scanf("%d", &t);
		maxi = max(maxi, t);
		mini = min(mini, t);
	}

	printf("%d %d", mini, maxi);
}