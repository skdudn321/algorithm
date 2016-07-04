#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int sum = 0;
	int temp;

	for (int i = 0; i < 5; i++){
		scanf("%d", &temp);
		if (temp >= 40){
			sum += temp;
		}
		else{
			sum += 40;
		}
	}

	printf("%d", sum / 5);
}