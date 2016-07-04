#include<stdio.h>
#include<string.h>

char str[1000000];
char str2[1000000];

int main(void){
	int len;

	while (true){
		gets(str);
		len = strlen(str);
		if (len == 3 && str[0] == 'E' && str[1] == 'N' && str[2] == 'D'){
			break;
		}
		for (int i = 0; i < len; i++){
			str2[i] = str[len - 1 - i];
		}
		str2[len] = 0;

		printf("%s\n", str2);
	}
}