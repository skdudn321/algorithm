#include<stdio.h>
#include<string.h>

int check1[27];
int check2[27];

char str[101];

int main(void) {
	int N, len, len2, sum = 0, cal;

	scanf("%d\n", &N);

	scanf("%s\n", str);

	len = strlen(str);
	for (int i = 0; i < len; i++) {
		check1[str[i] - 'A' + 1]++;
	}

	for (int i = 2; i <= N; i++) {
		scanf("%s\n", str);
		len2 = strlen(str);
		for (int j = 1; j <= 26; j++) {
			check2[j] = 0;
		}
		for (int j = 0; j < len2; j++) {
			check2[str[j] - 'A' + 1]++;
		}
		cal = 0;
		for (int j = 1; j <= 26; j++) {
			if (check1[j] > check2[j]) {
				cal += check1[j] - check2[j];
			}
			else {
				cal += check2[j] - check1[j];
			}
		}

		if (cal == 0 || cal == 1 || ((len2 == len) && cal == 2)) {
			sum++;
		}
	}

	printf("%d", sum);
}