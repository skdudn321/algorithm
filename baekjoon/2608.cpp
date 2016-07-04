#include<stdio.h>
#include<string.h>

char str[2][100];
char str3[100];

int change_num(int num);
void make_loma(int num);

int main(void) {
	int num1, num2;

	scanf("%s\n%s", str[0], str[1]);
	num1 = change_num(0);
	num2 = change_num(1);
	make_loma(num1 + num2);

	printf("%d\n%s", num1 + num2, str3);
}

int change_num(int num) {
	int index = 0;
	int len = strlen(str[num]);
	int sum = 0;

	while (index < len) {
		switch (str[num][index]) {
		case 'I':
			if (str[num][index + 1] == 'V' || str[num][index + 1] == 'X') {
				sum -= 1;
			}
			else {
				sum += 1;
			}
			break;
		case 'X':
			if (str[num][index + 1] == 'L' || str[num][index + 1] == 'C') {
				sum -= 10;
			}
			else {
				sum += 10;
			}
			break;
		case 'C':
			if (str[num][index + 1] == 'D' || str[num][index + 1] == 'M') {
				sum -= 100;
			}
			else {
				sum += 100;
			}
			break;
		case 'V':
			sum += 5;
			break;
		case 'L':
			sum += 50;
			break;
		case 'D':
			sum += 500;
			break;
		case 'M':
			sum += 1000;
			break;
		}
		index++;
	}

	return sum;
}
void make_loma(int num) {
	int check;
	int index = 0;

	check = num / 1000;
	num %= 1000;

	for (int i = 1; i <= check; i++) {
		str3[index++] = 'M';
	}

	check = num / 100;
	num %= 100;

	if (check == 9) {
		str3[index++] = 'C';
		str3[index++] = 'M';
	}
	else if (check >= 5) {
		str3[index++] = 'D';
		for (int i = 6; i <= check; i++) {
			str3[index++] = 'C';
		}
	}
	else if (check == 4) {
		str3[index++] = 'C';
		str3[index++] = 'D';
	}
	else {
		for (int i = 1; i <= check; i++) {
			str3[index++] = 'C';
		}
	}

	check = num / 10;
	num %= 10;

	if (check == 9) {
		str3[index++] = 'X';
		str3[index++] = 'C';
	}
	else if (check >= 5) {
		str3[index++] = 'L';
		for (int i = 6; i <= check; i++) {
			str3[index++] = 'X';
		}
	}
	else if (check == 4) {
		str3[index++] = 'X';
		str3[index++] = 'L';
	}
	else {
		for (int i = 1; i <= check; i++) {
			str3[index++] = 'X';
		}
	}

	check = num;

	if (check == 9) {
		str3[index++] = 'I';
		str3[index++] = 'X';
	}
	else if (check >= 5) {
		str3[index++] = 'V';
		for (int i = 6; i <= check; i++) {
			str3[index++] = 'I';
		}
	}
	else if (check == 4) {
		str3[index++] = 'I';
		str3[index++] = 'V';
	}
	else {
		for (int i = 1; i <= check; i++) {
			str3[index++] = 'I';
		}
	}

	str3[index] = 0;
}