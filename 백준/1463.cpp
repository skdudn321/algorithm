#include<stdio.h>

int dp_table[1000001];

int main(void){
	int i, N;

	dp_table[1] = 0;
	dp_table[2] = 1;
	dp_table[3] = 1;

	for (i = 4; i <= 1000000; i++){
		if (i % 6 == 0){
			dp_table[i] = dp_table[i / 2] > dp_table[i - 1] ? dp_table[i - 1] + 1 : dp_table[i / 2] + 1;
			dp_table[i] = dp_table[i / 3] + 1 > dp_table[i] ? dp_table[i] : dp_table[i / 3] + 1;
		}
		else if (i % 2 == 0){
			dp_table[i] = dp_table[i / 2] > dp_table[i - 1] ? dp_table[i - 1] + 1 : dp_table[i / 2] + 1;
		}
		else if (i % 3 == 0){
			dp_table[i] = dp_table[i / 3] > dp_table[i - 1] ? dp_table[i - 1] + 1 : dp_table[i / 3] + 1;
		}
		else{
			dp_table[i] = dp_table[i - 1] + 1;
		}
	}
	
	scanf("%d", &N);
	printf("%d", dp_table[N]);
}