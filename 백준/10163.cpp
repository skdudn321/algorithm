#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int paper[102][102];
int ans[101];

int main(void){
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		int x, y, up, right;
		scanf("%d %d %d %d", &x, &y, &right, &up);
		for (int j = x; j < x + right; j++){
			for (int k = y; k < y + up; k++){
				paper[j][k] = i;
			}
		}
	}

	for (int i = 0; i <= 101; i++){
		for (int j = 0; j <= 101; j++){
			ans[paper[i][j]]++;
		}
	}
	
	for (int i = 1; i <= N; i++){
		printf("%d\n", ans[i]);
	}
}