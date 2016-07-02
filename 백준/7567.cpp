#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int N = 3;
char temp;
int ans;

int main(void){
	while ((temp = getchar()) != EOF){
		if (temp == '('){
			if (N == 0){
				ans += 5;
			}
			else{
				ans += 10;
				N = 0;
			}
		}
		else if(temp == ')'){
			if (N == 1){
				ans += 5;
			}
			else{
				ans += 10;
				N = 1;
			}
		}
	}
	printf("%d", ans);
}