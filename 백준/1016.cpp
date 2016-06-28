#include<stdio.h>

int num[2000000];

int main(void){
	long long int min, max, temp, temp2, j;
	long long int i = 2, answer = 0;
	scanf("%lld %lld", &min, &max);

	while (true){
		temp = i * i;
		if (temp > max){
			break;
		}

		j = min / temp;
		if (min % temp != 0){
			j++;
		}
		while (true){
			temp2 = j * temp;
			if (temp2 > max){
				break;
			}

			num[temp2 - min] = 1;
			j++;
		}
		i++;
	}

	for (i = 0; i <= max - min; i++){
		if (num[i] == 0){
			answer++;
		}
	}

	printf("%lld", answer);
}