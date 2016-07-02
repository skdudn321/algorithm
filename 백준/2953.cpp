#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int ans = 0;
int ans2;

int main(void){
	int a, b, c, d;
	for (int i = 1; i <= 5; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (ans < a + b + c + d){
			ans = a + b + c + d;
			ans2 = i;
		}
	}
	printf("%d %d", ans2, ans);
}