#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int ans;

int main(void){
	int money;
	scanf("%d", &money);
	money = 1000 - money;

	ans += money / 500;
	money %= 500;
	ans += money / 100;
	money %= 100;
	ans += money / 50;
	money %= 50;
	ans += money / 10;
	money %= 10;
	ans += money / 5;
	money %= 5;
	ans += money;

	printf("%d", ans);
}