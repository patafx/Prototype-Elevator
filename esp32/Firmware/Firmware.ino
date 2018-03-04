/**
 * VERSION 0.0.0 BETA
 */

#include "TFTLib.h"

Display display = Display();
bool wifi = false;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  display.setup();
  display.bootScreen(); 
  for (int i = 0; i <= 100; i+=10) {
	  display.setBootProgress(i);
	  if (i % 10 == 0) {
		  display.setBootMessage("Progress " + String(i) + " %");
	  }
  }
  display.mainScreen();
}
void loop() {
  // put your main code here, to run repeatedly:
  /*for (int i=0;i<=100;i++) {
    display.setBootProgress(i);
    if (i%10 == 0) {
      display.setBootMessage("Progress "+String(i)+" %");
    }
  }
  delay(100);*/
	display.setMainCall1(true);
	display.setMainMove(1);
	for (int i = 0; i <= 100; i++) {
		display.setMainPosition(i);
		delay(50);
		if (i == 50) {
			display.setMainCall0(true);
		}
	}
	display.setMainMove(0);
	display.setMainCall1(false);
	display.setMainDoor(true);
	delay(1000);
	display.setMainDoor(false);
	display.setMainMove(-1);
	for (int i = 100; i > 0; i--) {
		display.setMainPosition(i);
		delay(50);
	}
	display.setMainCall0(false);
	display.setMainMove(0);
	display.setMainDoor(true);
	delay(1000);
	display.setMainDoor(false);
	delay(1500);
}
