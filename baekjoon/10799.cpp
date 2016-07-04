#include<stdio.h>

int main(void){
	int answer = 0;
	int count = 0;

	char temp, temp2;

	while ((temp = getchar()) != EOF){
		if (temp == '('){
			temp2 = getchar();
			if (temp2 == ')'){
				answer += count;
			}
			else{
				ungetc(temp2, stdin);
				count++;
				answer++;
			}
		}
		else{
			count--;
		}
	}

	printf("%d", answer);
}