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
	int N, M, length, che = 0;
	char str[10];

	scanf("%d %d", &N, &M);
	sprintf(str, "%d", N);
	length = strlen(str);

	for (int i = 1; i <= N; i++){
		for (int j = 0; j < length; j++){
			printf("%c", str[j]);
			che++;
			if (che == M){
				return 0;
			}
		}
	}
}