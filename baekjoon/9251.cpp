#include<stdio.h>
#include<string.h>

char str1[1010], str2[1010];
int dp_table[1010][1010];

int main(void) {
	int i, j;
	int len1, len2;

	scanf("%s\n%s", str1, str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
			}
			else {
				dp_table[i][j] = dp_table[i - 1][j] > dp_table[i][j - 1] ? dp_table[i - 1][j] : dp_table[i][j - 1];
			}
		}
	}

	printf("%d", dp_table[len1][len2]);
}