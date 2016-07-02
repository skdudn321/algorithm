#include<stdio.h>
#include<string.h>

char str[150];

int main(void) {
	int len;

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			printf("0");
			return 0;
		}
	}

	printf("1");
}