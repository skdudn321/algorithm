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
	int a, b;
	int c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	printf("%d", min(a + d, b + c));
}