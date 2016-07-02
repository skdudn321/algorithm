#include<stdio.h>
#include<string.h>

int dp_table[1010][1010];
char str1[1010], str2[1010], str3[1010];

int main(void){
	int i, j, k;
	int len1, len2;
	int max;
    
	scanf("%s\n", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (i = 1; i <= len1; i++){
		for (j = 1; j <= len2; j++){
			if (str1[i - 1] == str2[j - 1]){
				dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
			}
			else{
				dp_table[i][j] = dp_table[i - 1][j] > dp_table[i][j - 1] ? dp_table[i - 1][j] : dp_table[i][j - 1];
			}
		}
	}

	max = dp_table[len1][len2];
	i = len1;
	j = len2;
	str3[max] = 0;

	while (max){
		if (str1[i - 1] == str2[j - 1]){
			max--;
			str3[max] = str1[i - 1];
			i--;
			j--;
		}
		else{
			if (dp_table[i - 1][j] == dp_table[i][j]){
				i--;
			}
			else{
				j--;
			}
		}
	}

	printf("%d\n%s", dp_table[len1][len2], str3);
}