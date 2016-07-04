#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int num[10001];
int god;

int main(void){
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int temp;
		scanf("%d", &temp);
		num[temp]++;
		god = max(god, temp);
	}
	for (int i = 1; i <= god; i++){
		for (int j = 1; j <= num[i]; j++){
			printf("%d\n", i);
		}
	}
}