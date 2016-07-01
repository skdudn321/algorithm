#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temp1[20];
char temp2[20];

char str1[20];
char str2[20];
char str3[20];

void rev(char * str, char * str2);

int main(void){
	int X, Y, Z;

	scanf("%s %s", temp1, temp2);
	rev(str1, temp1);
	rev(str2, temp2);

	X = atoi(str1);
	Y = atoi(str2);
	Z = X + Y;

	sprintf(temp1, "%d", Z);
	rev(str3, temp1);
	Z = atoi(str3);

	printf("%d", Z);
}

void rev(char * str, char * str2){
	int len;
	len = strlen(str2);

	for (int i = 0; i < len; i++){
		str[i] = str2[len - i - 1];
	}
	str[len] = 0;
}