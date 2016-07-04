#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int poc[2100000];
int N = 1048576;

void change(int ind, int num);
int find(int ind);

int main(void){
	int T;

	
	scanf("%d", &T);
	int temp1, temp2, temp3;
	for (int i = 0; i < T; i++){
		scanf("%d", &temp1);
		if (temp1 == 1){
			scanf("%d", &temp2);
			temp3 = find(temp2);
			printf("%d\n", temp3 - 1048575);
			change(temp3, -1);
		}
		else{
			scanf("%d %d", &temp2, &temp3);
			change(temp2 + 1048575, temp3);
		}
	}
}

void change(int ind, int num){
	while (ind >= 1){
		poc[ind] += num;
		ind /= 2;
	}
}
int find(int ind){
	int temp = 0, r_value = 1;
	while (r_value < N){
		if (poc[r_value * 2] + temp < ind){
			temp += poc[r_value * 2];
			r_value = r_value * 2 + 1;
		}
		else{
			r_value *= 2;
		}
	}

	return r_value;
}