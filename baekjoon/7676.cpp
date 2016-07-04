#include<stdio.h>
#include<algorithm>

using namespace std;

int army[1001];

int main(void){
	int length, num;
	int start, count;

	while (true){
		scanf("%d %d", &length, &num);
		if (length == -1 && num == -1){
			break;
		}
		for (int i = 0; i < num; i++){
			scanf("%d", &army[i]);
		}
		sort(army, army + num);
		army[num] = 1000000000;
		start = army[0];
		count = 0;
		for (int i = 0; i < num; i++){
			if (army[i + 1] - start <= length){
				continue;
			}
			count++;
			int j = i;
			while (army[j] - army[i] <= length){
				j++;
			}

			i = j - 1;
			start = army[j];
		}

		printf("%d\n", count);
	}
}