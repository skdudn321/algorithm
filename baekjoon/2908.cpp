#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

lli A, B;
char f1[100], f2[100];

int main(void) {
	scanf("%lld %lld", &A, &B);
	sprintf(f1, "%lld", A);
	sprintf(f2, "%lld", B);

	int length1 = strlen(f1);
	int length2 = strlen(f2);
	int larger = 0;

	if (length1 > length2) {
		for (int i = length1 - 1; i >= 0; i--) {
			printf("%c", f1[i]);
		}
	}
	else if(length1 < length2){
		for (int i = length2 - 1; i >= 0; i--) {
			printf("%c", f2[i]);
		}
	}
	else {
		for (int i = length1 - 1; i >= 0; i--) {
			if (f1[i] > f2[i]) {
				larger = 1;
				break;
			}
			if (f2[i] > f1[i]) {
				larger = 2;
				break;
			}
		}
	}

	if (larger == 1) {
		for (int i = length1 - 1; i >= 0; i--) {
			printf("%c", f1[i]);
		}
	}
	else {
		for (int i = length2 - 1; i >= 0; i--) {
			printf("%c", f2[i]);
		}
	}
}