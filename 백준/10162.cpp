#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int A, B, C;

int main(void){
	int num;
	scanf("%d", &num);

	A = (num / 300);
	num %= 300;
	B = (num / 60);
	num %= 60;
	C = (num / 10);
	num %= 10;

	if (num != 0){
		printf("-1");
	}
	else{
		printf("%d %d %d", A, B, C);
	}
}