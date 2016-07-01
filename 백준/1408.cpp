#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int a, b, c;
	int A, B, C;

	scanf("%d:%d:%d", &a, &b, &c);
	scanf("%d:%d:%d", &A, &B, &C);

	C -= c;
	if (C < 0){
		B--;
		C += 60;
	}
	B -= b;
	if (B < 0){
		A--;
		B += 60;
	}
	A -= a;
	if (A < 0){
		A += 24;
	}

	printf("%02d:%02d:%02d", A, B, C);
}