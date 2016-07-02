#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int sum, temp;
	scanf("%d", &sum);
	for (int i = 0; i < 9; i++){
		scanf("%d", &temp);
		sum -= temp;
	}
	printf("%d", sum);
}