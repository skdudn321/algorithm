#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

long long int S;
int N;

int main(void){
	int i;
	scanf("%lld", &S);
	for (i = 1; i <= S; i++){
		S -= i;
	}
	printf("%d", i - 1);
}