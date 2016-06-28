#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int ans = 0;

int main(void){
	char temp;


	while ((temp = getchar()) != EOF){
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')){
			ans++;
			while ((temp = getchar()) != EOF){
				if (temp == ' '){
					break;
				}
			}
		}
	}

	printf("%d", ans);
}