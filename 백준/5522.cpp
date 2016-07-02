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
	int sum = 0;

	for (int i = 1; i <= 5; i++){
		int temp;
		scanf("%d", &temp);
		sum += temp;
	}
    printf("%d", sum);
}