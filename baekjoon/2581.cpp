#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int sosu[10001];

int main(void){
	int N, M, sum = 0, mina = 100000000;
	bool check = true;
	
	sosu[1] = 1;
	for (int i = 2; i <= 10000; i++){
		if (sosu[i] == 0){
			for (int j = 2; i * j <= 10000; j++){
				sosu[i * j] = 1;
			}
		}
	}

	scanf("%d %d", &N, &M);
	for (int i = N; i <= M; i++){
		if (sosu[i] == 0){
			sum += i;
			mina = min(mina, i);
		}
	}

	if (mina == 100000000){
		printf("-1");
	}
	else{
		printf("%d\n%d", sum, mina);
	}
}