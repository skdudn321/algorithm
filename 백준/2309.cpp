#include<stdio.h>
#include<algorithm>

using namespace std;

int nanjang[10];

int main(void) {
	int sum = 0;
	int i, j, k;
	for (i = 1; i <= 9; i++) {
		scanf("%d", &nanjang[i]);
		sum += nanjang[i];
	}
	sort(nanjang + 1, nanjang + 10);

	for (i = 1; i <= 8; i++) {
		sum -= nanjang[i];
		for (j = i + 1; j <= 9; j++) {
			sum -= nanjang[j];
			if (sum == 100) {
				for (k = 1; k <= 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					printf("%d\n", nanjang[k]);
				}
				return 0;
			}
			sum += nanjang[j];
		}
		sum += nanjang[i];
	}
}