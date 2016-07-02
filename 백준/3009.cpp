#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int x[1001], y[1001];

int main(void){
	int a, b;
	for (int i = 0; i < 3; i++){
		scanf("%d %d", &a, &b);
		if (x[a] == 1){
			x[a] = 0;
		}
		else{
			x[a] = 1;
		}
		if (y[b] == 1){
			y[b] = 0;
		}
		else{
			y[b] = 1;
		}
	}

	for (int i = 0; i < 1000; i++){
		if (x[i]){
			printf("%d ", i);
		}
	}
	for (int i = 0; i < 1000; i++){
		if (y[i]){
			printf("%d ", i);
		}
	}
}