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
	int a, b, c, d, p;
	int temp;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
	if (c < p){
		temp = b + (p - c) * d;
	}
	else{
		temp = b;
	}

	printf("%d", min(a * p , temp));
}