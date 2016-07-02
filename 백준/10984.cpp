#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int N;
		double sum = 0;
		int sum2 = 0;
		int temp2;
		double temp;
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			scanf("%d %lf", &temp2, &temp);
			sum += temp2 * temp;
			sum2 += temp2;
		}
		printf("%d %.1lf\n", sum2, sum / sum2);
	}
}