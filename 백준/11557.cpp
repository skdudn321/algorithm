#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

char str[100];
char str2[100];
int sul;
int r_value;

int main(void){
	int T, N;


	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		scanf("%d\n", &N);
		for (int j = 0; j < N; j++){
			scanf("%s %d\n", str, &sul);
			if (sul > r_value){
				r_value = sul;
				strcpy(str2, str);
			}
		}
		printf("%s\n", str2);
	}
}