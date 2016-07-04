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
	scanf("%d", &N);
	N += 56;
	N %= 60;

	printf("%c%d", 'A' + N % 12, N % 10);
}