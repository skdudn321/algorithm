#include<stdio.h>
#include<string.h>

int dp_table[5000][5000];

char str1[5000], str2[5000];

int main(void) {
	int length1, length2;
	int i, j;
	int answer = 0;

	scanf("%s\n", str1 + 1);
	scanf("%s", str2 + 1);
	
	length1 = strlen(str1 + 1);
	length2 = strlen(str2 + 1);

	for (i = 1; i <= length1; i++) {
		for (j = 1; j <= length2; j++) {
			if (str1[i] == str2[j]) {
				dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
				if (dp_table[i][j] > answer) {
					answer = dp_table[i][j];
				}
			}
		}
	}

	printf("%d\n", answer);
}