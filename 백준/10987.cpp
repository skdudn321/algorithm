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
		if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
			ans++;
			
		}
	}

	printf("%d", ans);
}