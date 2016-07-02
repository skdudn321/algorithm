#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

int main(void){
	double temp;
	int N;
	char ttemp;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++){
		scanf("%lf", &temp);
		while ((ttemp = getchar()) == ' '){
			ttemp = getchar();
			if (ttemp == '@'){
				temp *= 3;
			}
			else if (ttemp == '%'){
				temp += 5;
			}
			else{
				temp -= 7;
			}
		}
		ungetc(ttemp, stdin);
		printf("%.2lf\n", temp);
	}
}