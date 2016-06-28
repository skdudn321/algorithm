#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> ii;
ii line[50];

int main(void){
	int N, temp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		line[i] = ii(temp, i);
	}
	sort(line, line + N);

	for (int i = 0; i < N; i++){
		line[i] = ii(line[i].second, i);
	}
	sort(line, line + N);

	for (int i = 0; i < N; i++){
		printf("%d", line[i].second);
		if (i != N - 1){
			printf(" ");
		}
	}
}