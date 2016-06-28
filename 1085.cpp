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
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	printf("%d", min(min(x, w - x), min(y, h - y)));
}