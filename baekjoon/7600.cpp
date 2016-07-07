#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

char str[300];
int alph[30];

int main(void){
	gets(str);
	while (str[0] != '#'){
		for (int i = 0; i < 26; i++){
			alph[i] = 0;
		}
		int len = strlen(str);
		for (int i = 0; i < len; i++){
			if (str[i] >= 'a' && str[i] <= 'z'){
				alph[str[i] - 'a'] = 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z'){
				alph[str[i] - 'A'] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; i++){
			if (alph[i] == 1){
				ans++;
			}
		}
		printf("%d\n", ans);
		gets(str);
	}
}