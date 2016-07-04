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
	int T, N;
	char str[30];
	long long int ans;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++){
		scanf("%s\n", &str);
		int len = strlen(str);
		if (str[0] >= '5'){
			str[0] = '5';
			for (int j = 1; j < len; j++){
				str[j] = '0';
			}
		}
		N = atoi(str);
		long long int temp = 1;
		while (temp <= N){
			temp *= 10;
		}
		temp -= 1;
		temp -= N;
		ans = (long long int)N * temp;
		printf("%lld\n", ans);
	}
}