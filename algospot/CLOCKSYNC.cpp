#include<stdio.h>

#define TRUE 0
#define FALSE -1

int CLOCK[16];
int SWITCH_NUM;

void CHANGE_CLOCK(int num);
void SWITCH_PUSH(int clock_num, void(*SWITCH)(void));

void SWITCH0(void);
void SWITCH1(void);
void SWITCH2(void);
void SWITCH3(void);
void SWITCH4(void);
void SWITCH5(void);
void SWITCH6(void);
void SWITCH7(void);
void SWITCH8(void);
void SWITCH9(void);

int main(void) {
	int Check_Num;
	int i;
	int RESULT;
	scanf("%d", &Check_Num);
	for (i = 0; i<Check_Num; i++) {
		scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &CLOCK[0], &CLOCK[1], &CLOCK[2], &CLOCK[3], &CLOCK[4], &CLOCK[5], &CLOCK[6], &CLOCK[7], &CLOCK[8], &CLOCK[9], &CLOCK[10], &CLOCK[11], &CLOCK[12], &CLOCK[13], &CLOCK[14], &CLOCK[15]);
		SWITCH_NUM = 0;
		RESULT = TRUE;
		if (CLOCK[8] == CLOCK[12]) {
			SWITCH_PUSH(8, SWITCH4);
			SWITCH_PUSH(11, SWITCH1);
			SWITCH_PUSH(13, SWITCH9);
			SWITCH_PUSH(10, SWITCH2);
			SWITCH_PUSH(6, SWITCH3);
			SWITCH_PUSH(7, SWITCH7);
			SWITCH_PUSH(4, SWITCH8);
			SWITCH_PUSH(3, SWITCH6);
			SWITCH_PUSH(1, SWITCH0);
			if (CLOCK[9] == 12 && CLOCK[5] == 12 && CLOCK[0] == CLOCK[2] && CLOCK[2] == CLOCK[14] && CLOCK[14] == CLOCK[15]) {
				SWITCH_PUSH(0, SWITCH5);
				RESULT = SWITCH_NUM;
			}
			else {
				RESULT = FALSE;
			}
		}
		else {
			RESULT = FALSE;
		}

		printf("%d\n", RESULT);
	}
}

void CHANGE_CLOCK(int num) {
	int time = CLOCK[num];
	time += 3;
	if (time == 15) {
		time = 3;
	}
	CLOCK[num] = time;
}
void SWITCH_PUSH(int clock_num, void(*SWITCH)(void)) {
	int push_num = (12 - CLOCK[clock_num]) / 3;
	for (; push_num>0; push_num--) {
		SWITCH();
	}
}

void SWITCH0(void) {
	CHANGE_CLOCK(0);
	CHANGE_CLOCK(1);
	CHANGE_CLOCK(2);
	SWITCH_NUM++;
}
void SWITCH1(void) {
	CHANGE_CLOCK(3);
	CHANGE_CLOCK(7);
	CHANGE_CLOCK(9);
	CHANGE_CLOCK(11);
	SWITCH_NUM++;
}
void SWITCH2(void) {
	CHANGE_CLOCK(4);
	CHANGE_CLOCK(10);
	CHANGE_CLOCK(14);
	CHANGE_CLOCK(15);
	SWITCH_NUM++;
}
void SWITCH3(void) {
	CHANGE_CLOCK(0);
	CHANGE_CLOCK(4);
	CHANGE_CLOCK(5);
	CHANGE_CLOCK(6);
	CHANGE_CLOCK(7);
	SWITCH_NUM++;
}
void SWITCH4(void) {
	CHANGE_CLOCK(6);
	CHANGE_CLOCK(7);
	CHANGE_CLOCK(8);
	CHANGE_CLOCK(10);
	CHANGE_CLOCK(12);
	SWITCH_NUM++;
}
void SWITCH5(void) {
	CHANGE_CLOCK(0);
	CHANGE_CLOCK(2);
	CHANGE_CLOCK(14);
	CHANGE_CLOCK(15);
	SWITCH_NUM++;
}
void SWITCH6(void) {
	CHANGE_CLOCK(3);
	CHANGE_CLOCK(14);
	CHANGE_CLOCK(15);
	SWITCH_NUM++;
}
void SWITCH7(void) {
	CHANGE_CLOCK(4);
	CHANGE_CLOCK(5);
	CHANGE_CLOCK(7);
	CHANGE_CLOCK(14);
	CHANGE_CLOCK(15);
	SWITCH_NUM++;
}
void SWITCH8(void) {
	CHANGE_CLOCK(1);
	CHANGE_CLOCK(2);
	CHANGE_CLOCK(3);
	CHANGE_CLOCK(4);
	CHANGE_CLOCK(5);
	SWITCH_NUM++;
}
void SWITCH9(void) {
	CHANGE_CLOCK(3);
	CHANGE_CLOCK(4);
	CHANGE_CLOCK(5);
	CHANGE_CLOCK(9);
	CHANGE_CLOCK(13);
	SWITCH_NUM++;
}