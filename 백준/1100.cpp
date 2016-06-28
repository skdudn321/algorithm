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
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (getchar() == 'F'){
				ans++;
			}
			getchar();
		}
		getchar();
		getchar();
		for (int j = 0; j < 4; j++){
			if (getchar() == 'F'){
				ans++;
			}
			getchar();
		}
	}

	printf("%d", ans);
}