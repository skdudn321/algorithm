#include<stdio.h>

int heap[100001];

int change(int ind1, int ind2){
	int temp;
	if(heap[ind1] > heap[ind2]){
		temp = heap[ind2];
		heap[ind2] = heap[ind1];
		heap[ind1] = temp;
		return 1;
	}
	return 0;
}

int main(void){
	int check = 0;
	int N, num;
	int i;
	int temp;
	
	scanf("%d", &N);

	for(i=0; i<N; i++){
		scanf("%d", &num);
		if(num == 0){
			if(check == 0){
				printf("0\n");
			}
			else{
				printf("%d\n", heap[1]);
				heap[1] = heap[check];
				check--;
			}

			if(check != 0){
				int nana = 1;
				while(check >= nana*2 + 1){
					if(heap[nana*2] < heap[nana*2+1]){
						if(change(nana, nana*2)){
							nana = nana*2;
						}
						else{
							break;
						}
					}
					else{
						if(change(nana, nana*2+1)){
							nana = nana*2 + 1;
						}
						else{
							break;
						}
					}
				}
				if(check == nana*2){
					change(nana, check);
				}
			}
		}
		else{
			int nana;
			check++;
			heap[check] = num;
			nana = check;
			while(nana != 1 &&change(nana/2, nana)){
				nana = nana/2;
			}
		}
	}

	return 0;
}