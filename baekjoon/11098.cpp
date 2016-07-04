#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int ans;
char str[1000];
char out[1000];
int temp;

int main(void){
	int T;

	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		ans = 0;
		int N;
		scanf("%d\n", &N);
		for (int j = 0; j < N; j++){
			scanf("%d %s\n", &temp, str);
			if (temp > ans){
				ans = temp;
				strcpy(out, str);
			}
		}

		printf("%s\n", out);
	}
}