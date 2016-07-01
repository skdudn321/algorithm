#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

bool table[2][501][501];
bool check[501];
int ans;

void check_init(void);

queue<int> qu;

int main(void){

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		table[0][x][y] = true;
		table[1][y][x] = true;
	}

	for (int i = 1; i <= N; i++){
		table[0][i][i] = true;
		table[1][i][i] = true;
	}

	for (int k = 0; k <= 1; k++){
		for (int i = 1; i <= N; i++){
			check_init();
			qu.push(i);
			while (!qu.empty()){
				if (!check[qu.front()]){
					qu.pop();
					continue;
				}
				for (int j = 1; j <= N; j++){
					if (check[j] && table[k][qu.front()][j]){
						qu.push(j);
						table[k][i][j] = true;
					}
				}
				check[qu.front()] = false;
				qu.pop();
			}
		}
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (!(table[0][i][j] || table[1][i][j])){
				break;
			}
			if (j == N){
				ans++;
			}
		}
	}

	printf("%d", ans);
}

void check_init(void){
	for (int i = 1; i <= 500; i++){
		check[i] = true;
	}
}