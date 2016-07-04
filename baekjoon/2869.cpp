#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int ans;

int main(void){
	int A, B, V;

	scanf("%d %d %d", &A, &B, &V);

	V -= A;
	if (V % (A - B) == 0){
		ans = V / (A - B) + 1;
	}
	else{
		ans = V / (A - B) + 2;
	}
	
	printf("%d", ans);
}