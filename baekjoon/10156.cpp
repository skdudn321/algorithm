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
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", max(0, a * b - c));
}