#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int a = 0, b = 0;
	char temp;

	while ((temp = getchar()) != EOF){
		if (temp == 'A'){
			a++;
		}
		if(temp == 'B'){
			b++;
		}
	}
	if (a > b){
		printf("A");
	}
	else if (a < b){
		printf("B");
	}
	else{
		printf("Tie");
	}
}