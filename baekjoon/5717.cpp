#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int a, b;

	while (1){
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0){
			return 0;
		}
		printf("%d\n", a + b);
	}
}