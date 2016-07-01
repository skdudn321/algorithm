#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int ans;

int main(void){
	int N;
	scanf("%d", &N);
	ans = (N / 5) + (N / 25) + (N / 125);
	printf("%d", ans);
}