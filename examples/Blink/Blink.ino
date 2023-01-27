#include <Timer.h> //přidání knihovny
void setup() {
  pinMode(13, OUTPUT); //nastavení vestavěné led na OUTPUT
}
void loop() {
  timerTick(); //zkontrolovat RTC
  timerStart(0); //zapnutí timeru číslo 0
  if (Timer[0] >= 1000) { //pokud timer čislo 0 přesáhl nebo je stejný jako 1000 (1s)
    timerStop(0); //vypnutí timeru číslo 0 
    digitalWrite(13, !digitalRead(13)); //nastavení vestavěné led na opak
  }
}
