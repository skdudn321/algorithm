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
	int N, M;
	char str[20];

	scanf("%d %d\n", &N, &M);

	for (int i = 0; i < N; i++){
		scanf("%s\n", str);
		for (int j = M - 1; j >= 0; j--){
			printf("%c", str[j]);
		}
		printf("\n");
	}
}