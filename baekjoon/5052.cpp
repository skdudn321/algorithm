#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;
char phone[10010][20];
char * p_phone[10010];
bool comp(char * a, char * b);

int main(void) {
	int T;
	int N;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int flag = true;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s\n", phone[j]);
			p_phone[j] = phone[j];
		}
		sort(p_phone, p_phone + N, comp);
		for (int j = 0; j < N - 1; j++) {
			int length1 = strlen(p_phone[j]);
			int length2 = strlen(p_phone[j + 1]);
			if (strncmp(p_phone[j], p_phone[j + 1], min(length1, length2)) == 0) {
				printf("NO\n");
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("YES\n");
		}
	}

	return 0;
}

bool comp(char * a, char * b) {
	int temp = strcmp(a, b);
	if (temp == 0) {
		int length1 = strlen(a), length2 = strlen(b);
		return length2 > length1;
	}
	else if ( temp > 0 ) {
		return false;
	}
	else {
		return true;
	}
}