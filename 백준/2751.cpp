#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int num[1000000];

int main(void){
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	for (int i = 0; i < N; i++){
		printf("%d\n", num[i]);
	}
}