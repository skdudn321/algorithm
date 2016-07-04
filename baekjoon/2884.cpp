#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	int T, M;

	scanf("%d %d", &T, &M);

	if (M > 45){
		M -= 45;
	}
	else{
		if (T == 0){
			T += 23;
			M += 15;
		}
		else{
			T -= 1;
			M += 15;
		}
	}

	printf("%d %d", T, M);
}