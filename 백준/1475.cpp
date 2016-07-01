#include<stdio.h>

int num[10];

int main(void){
	char temp;
	int sum = 0;

	while ((temp = getchar()) != EOF){
		if (temp == '6' || temp == '9'){
			if (num[6] > num[9]){
				num[9]++;
			}
			else{
				num[6]++;
			}
		}
		else{
			num[temp - '0']++;
		}

		for (int i = 0; i <= 9; i++){
			sum = sum > num[i] ? sum : num[i];
		}
	}

	printf("%d", sum);
}