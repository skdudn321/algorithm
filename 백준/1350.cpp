#include<stdio.h>

int main(void){
	int N, clu;
	int file[1000];
	long long int sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &file[i]);
	}

	scanf("%d", &clu);

	for (int i = 0; i < N; i++){
		sum += file[i] / clu;
		if (file[i] % clu != 0){
			sum++;
		}
	}

	sum *= clu;

	printf("%lld", sum);
}