#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<time.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;

int main(void) {
	struct tm *t;
	time_t timev;
	time(&timev);
	t = localtime(&timev);
	printf("%d-0%d-0%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}