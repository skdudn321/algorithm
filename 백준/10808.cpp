#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int table[27];

int main(void){
	char temp;


	while ((temp = getchar()) != EOF){
		table[temp - 'a' + 1]++;
	}

	for (int i = 1; i <= 26; i++){
		printf("%d ", table[i]);
	}
}