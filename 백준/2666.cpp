#include<stdio.h>

int bae[20];
int open;

int recursion(int num1, int num2, int index);

int main(void){
	int num1, num2;
	int length;
	int i, temp;
	int answer;

	scanf("%d %d %d %d", &length, &num1, &num2, &open);
	if (num1 > num2){
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	for (i = 0; i < open; i++){
		scanf("%d", &bae[i]);
	}

	answer = recursion(num1, num2, 0);
	printf("%d\n", answer);
}

int recursion(int num1, int num2, int index){
	int temp1, temp2;

	if (index == open - 1){
		if (bae[index] > num2){
			return bae[index] - num2;
		}
		else if (bae[index] == num2){
			return 0;
		}
		else if (bae[index] < num1){
			return num1 - bae[index];
		}
		else if (bae[index] == num1){
			return 0;
		}
		else{
			return ((num2 - bae[index] > bae[index] - num1) ? bae[index] - num1 : num2 - bae[index]);
		}
	}
	else{
		if (bae[index] > num2){
			return bae[index] - num2 + recursion(num1, bae[index], index + 1);
		}
		else if (bae[index] == num2){
			return recursion(num1, num2, index + 1);
		}
		else if (bae[index] < num1){
			return num1 - bae[index] + recursion(bae[index], num2, index + 1);
		}
		else if (bae[index] == num1){
			return recursion(num1, num2, index + 1);
		}
		else{
			temp1 = num2 - bae[index] + recursion(num1, bae[index], index + 1);
			temp2 = bae[index] - num1 + recursion(bae[index], num2, index + 1);
			return ((temp1 > temp2) ? temp2 : temp1);
		}
	}
}