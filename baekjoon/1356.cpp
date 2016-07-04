#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int N;
	int left, right;
	int len;
	int zcount = 0;
	char str[20];
	scanf("%d", &N);

	sprintf(str, "%d", N);
	len = strlen(str);
	left = 1;
	right = 1;

	for (int i = 0; i < len; i++){
		if (str[i] == '0'){
			zcount++;
		}
	}

	if (len == 1){
		printf("NO");
		return 0;
	}
	if (zcount == 1){
		printf("NO");
		return 0;
	}
	else if (zcount > 1){
		printf("YES");
		return 0;
	}
	
	for (int i = 0; i < len; i++){
		right *= (str[i] - '0');
	}

	for (int i = 0; left <= right; i++){
		left *= (str[i] - '0');
		right /= (str[i] - '0');

		if (left == right){
			printf("YES");
			return 0;
		}
	}

	printf("NO");
}