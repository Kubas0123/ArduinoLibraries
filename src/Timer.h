#include <Arduino.h>
int Timer[] = {
  0, 0, 0, 0, 0, 0
};
bool TimerInUse[] = {
  0, 0, 0, 0, 0, 0
};
int TimerCount = 6;
int perLoop = 0;
unsigned int Total = 0;
unsigned long Start = 0;
unsigned long Current = 0;
void timerStart(int DelayNum) {
	if (TimerInUse[DelayNum] == false){
		Timer[DelayNum] = 0;
		TimerInUse[DelayNum] = true;
	}
}
void timerStop(int DelayNum) {
	Timer[DelayNum] = 0;
	TimerInUse[DelayNum] = false;
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
		if (TimerInUse[i] == true){
			Timer[i] = Timer[i] + perLoop;
		}
	}
}
