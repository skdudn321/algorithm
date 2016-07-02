#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int Q1, Q2, Q3, Q4, AXIS;

int main(void){
	int N;
	int x, y;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d %d", &x, &y);
		if (x > 0){
			if (y > 0){
				Q1++;
			}
			else if (y < 0){
				Q4++;
			}
			else{
				AXIS++;
			}
		}
		else if (x < 0){
			if (y > 0){
				Q2++;
			}
			else if (y < 0){
				Q3++;
			}
			else{
				AXIS++;
			}
		}
		else{
			AXIS++;
		}
	}

	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", Q1, Q2, Q3, Q4, AXIS);
}