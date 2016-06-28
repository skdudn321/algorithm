#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int ans = 0;

int table[40][2];

int main(void){
	int N, temp;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		scanf("%d %d", &table[i][0], &table[i][1]);
	}

	for (int i = 1; i <= N - 2; i++){
		for (int j = i + 1; j <= N - 1; j++){
			for (int k = j + 1; k <= N; k++){
				temp = table[i][0] * table[j][1] + table[j][0] * table[k][1] + table[k][0] * table[i][1];
				temp = temp - table[i][1] * table[j][0] - table[j][1] * table[k][0] - table[k][1] * table[i][0];
				if (temp < 0){
					temp = -temp;
				}
				ans = max(temp, ans);
			}
		}
	}

	printf("%.1lf", (double)ans / 2);
}