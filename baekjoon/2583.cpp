#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int map[110][110];
int check[110][110];
int squ;
int num;
vector<int> ve;

void recursion(int x, int y);

int main(void){
	int N, M, Z;
	int i, j, k;
	int x1, y1, x2, y2;

	scanf("%d %d %d", &M, &N, &Z);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			map[i][j] = 1;
		}
	}

	for (i = 0; i < Z; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (j = x1 + 1; j <= x2; j++){
			for (k = y1 + 1; k <= y2; k++){
				map[j][k] = 0;
			}
		}
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			if (map[i][j]){
				num++;
				squ = 0;
				recursion(i, j);
				ve.push_back(squ);
			}
		}
	}

	sort(ve.begin(), ve.end());
	printf("%d\n", num);
	for (i = 0; i < (int)ve.size(); i++){
		printf("%d", ve[i]);
		if (i != (int)ve.size() - 1){
			printf(" ");
		}
	}
}

void recursion(int x, int y){
	squ++;
	map[x][y] = 0;
	if (map[x + 1][y]){
		recursion(x + 1, y);
	}
	if (map[x - 1][y]){
		recursion(x - 1, y);
	}
	if (map[x][y + 1]){
		recursion(x, y + 1);
	}
	if (map[x][y - 1]){
		recursion(x, y - 1);
	}
}