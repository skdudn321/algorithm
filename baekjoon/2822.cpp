#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

typedef pair<int, int> ii;
ii num[8];

int main(void){
	int sum = 0;

	for (int i = 0; i < 8; i++){
		int t1;
		scanf("%d", &t1);
		num[i] = ii(t1, i + 1);
	}
	sort(num, num + 8, greater<ii>());
	for (int i = 0; i < 5; i++){
		sum += num[i].first;
		num[i] = ii(num[i].second, num[i].first);
	}
	sort(num, num + 5);
	printf("%d\n", sum);
	for (int i = 0; i < 5; i++){
		printf("%d ", num[i].first);
	}
}