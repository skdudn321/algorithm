#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	char a, b;
	int score1 = 0, score2 = 0;

	scanf("%c%c", &a, &b);

	if (a == 'A'){
		score1 += 4;
	}
	else if (a == 'B'){
		score1 += 3;
	}
	else if (a == 'C'){
		score1 += 2;
	}
	else if (a == 'D'){
		score1 += 1;
	}

	if (b == '+'){
		score2 += 3;
	}
	else if (b == '-'){
		score2 += 7;
		score1 -= 1;
	}

	printf("%d.%d", score1, score2);
}