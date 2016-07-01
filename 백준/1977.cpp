#include<stdio.h>
#include<math.h>

int main(void){
	int M, N;
	int i, j;
	int min, sum = 0;

	scanf("%d %d", &M, &N);
	
	i = sqrt((double)M);
	j = sqrt((double)N);

	if (i * i == M){
		min = M;
		sum += M;
		i++;
	}
	else if (i == j){
		printf("-1\n");
		return 0;
	}
	else{
		i++;
		min = i * i;
	}

	for (; i <= j; i++){
		sum += i * i;
	}

	printf("%d\n%d", sum, min);
}