#include<stdio.h>

int main(void){
	int E, S, M;
	int i, j, k;

	scanf("%d %d %d", &E, &S, &M);
	S %= 28;
	M %= 19;

	while (true){
		if (E % 28 == S){
			if (E % 19 == M){
				break;
			}
		}
		E += 15;
	}

	printf("%d", E);
}
