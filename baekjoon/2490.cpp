#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
		int count = a + b + c + d;
		switch (count){
		case 0:
			printf("D\n");
			break;
		case 1:
			printf("C\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 3:
			printf("A\n");
			break;
		case 4:
			printf("E\n");
			break;
		}
	}
}