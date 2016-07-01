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
	int N;
	double grade[1001];
	double mm, sum = 0;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%lf", &grade[i]);
		mm = max(grade[i], mm);
	}
	for (int i = 1; i <= N; i++){
		grade[i] = grade[i] / mm * 100;
		sum += grade[i];
	}
	printf("%.2lf", sum / N);
}