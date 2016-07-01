#include<stdio.h>
#include<string.h>

int dp_table[200][200][200];

char str1[200], str2[200], str3[200];

int main(void) {
	int length1, length2, length3;
	int i, j, k;

	scanf("%s\n", str1 + 1);
	scanf("%s\n", str2 + 1);
	scanf("%s", str3 + 1);
	
	length1 = strlen(str1 + 1);
	length2 = strlen(str2 + 1);
	length3 = strlen(str3 + 1);

	for (i = 1; i <= length1; i++) {
		for (j = 1; j <= length2; j++) {
			for (k = 1; k <= length3; k++) {
				if ((str1[i] == str2[j]) && (str1[i] == str3[k])) {
					dp_table[i][j][k] = dp_table[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp_table[i][j][k] = dp_table[i - 1][j][k] > dp_table[i][j - 1][k] ? dp_table[i - 1][j][k] : dp_table[i][j - 1][k];
					dp_table[i][j][k] = dp_table[i][j][k] > dp_table[i][j][k - 1] ? dp_table[i][j][k] : dp_table[i][j][k - 1];
				}
			}
		}
	}

	printf("%d\n", dp_table[length1][length2][length3]);
}