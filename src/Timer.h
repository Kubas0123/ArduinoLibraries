#include <Arduino.h>
int Timer[] = {
  0, 0, 0, 0, 0, 0
};
int TimerInUse[] = {
  0, 0, 0, 0, 0, 0
};
int TimerCount = 6;
int perLoop = 0;
unsigned int Total = 0;
unsigned long Start = 0;
unsigned long Current = 0;
void timerStart(int DelayNum) {
	if (TimerInUse[DelayNum] == 0){
		Timer[DelayNum] = 0;
		TimerInUse[DelayNum] = 1;
	}
}
void timerStop(int DelayNum) {
	Timer[DelayNum] = 0;
	TimerInUse[DelayNum] = 0;
}
void timerTick() {
	Current = millis();
	if (Start > Current) {
		Start = (Start - 4294967295) * (-1);
		Current = Current + (Start * 2);
	}
	perLoop = Current - Start;
	Start = millis();
	for (int i = 0; i < TimerCount; i++) {
		if (TimerInUse[i] == 1){
			Timer[i] = Timer[i] + perLoop;
		}
	}
}