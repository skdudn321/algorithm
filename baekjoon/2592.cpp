#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

int ans;
int cou;
int check[1001];
int summ;

int main(void) {
	for (int i = 1; i <= 10; i++) {
		int temp;
		scanf("%d", &temp);
		check[temp]++;
		if (check[temp] > cou) {
			cou = check[temp];
			ans = temp;
		}
		summ += temp;
	}
	printf("%d\n%d", summ / 10, ans);
}