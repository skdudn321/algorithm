#include<stdio.h>
#include<stdlib.h>

typedef struct cost {
	int a;
	int b;
	int c;
}cost;

cost bae[100000];
int count[1001];
int checkbox[1001];

int compare(const void * a, const void * b);
int boxnum(int index);

int main(void) {
	int N;
	int M;
	int i, j;
	int a, b, c;
	int sum = 0;
	int check;
	int line;
	int box1, box2;

	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0, j = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a > N || b > N || a == b) {
			continue;
		}
		bae[j].a = a;
		bae[j].b = b;
		bae[j].c = c;
		j++;
	}

	M = j;
	if (M != 0) {
		qsort(bae, M, sizeof(cost), compare);
	}

	for (i = 0; i < 1001; i++) {
		checkbox[i] = i;
	}

	i = -1;
	check = 1;
	line = 0;
	while(line != N - 1) {
		i++;
		if (count[bae[i].a] == 0 && count[bae[i].b] == 0) {
			count[bae[i].a] = check;
			count[bae[i].b] = check;
			check++;
			sum += bae[i].c;
			line++;
		}
		else if (count[bae[i].a] == 0) {
			count[bae[i].a] = count[bae[i].b];
			sum += bae[i].c;
			line++;
		}
		else if (count[bae[i].b] == 0) {
			count[bae[i].b] = count[bae[i].a];
			sum += bae[i].c;
			line++;
		}
		else {
			box1 = boxnum(bae[i].a);
			box2 = boxnum(bae[i].b);
			if (checkbox[box1] == checkbox[box2]) {
				continue;
			}
			else {
				sum += bae[i].c;
				line++;
				if (checkbox[box1] > checkbox[box2]) {
					checkbox[box1] = checkbox[box2];
				}
				else {
					checkbox[box2] = checkbox[box1];
				}
			}
		}
	}

	printf("%d", sum);

	return 0;
}

int compare(const void * a, const void * b) {
	if ((*(cost *)a).c > (*(cost *)b).c) {
		return 1;
	}
	else if ((*(cost *)a).c < (*(cost *)b).c) {
		return -1;
	}
	else {
		return 0;
	}
}

int boxnum(int index) {
	index = count[index];
	while (checkbox[index] != index) {
		index = checkbox[index];
	}
	return index;
}