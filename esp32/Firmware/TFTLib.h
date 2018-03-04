#ifndef _TFT_LIB_H_
#define _TFT_LIB_H_

#include "pins.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define ICO_HEIGHT 16
#define ICO_WIDTH 16
const unsigned char PROGMEM ICO_WIFI[] =
{ 0, 0, 3, 192, 31, 248, 127, 254, 254, 63, 240, 15, 71, 226, 31, 248, 31, 248, 12, 48, 0, 0, 1, 128, 3, 192, 3, 192, 1, 128, 0, 0 };

const unsigned char PROGMEM ICO_WIFI_OFF[] = 
{ 0, 3, 3, 199, 31, 254, 127, 254, 254, 127, 240, 127, 71, 226, 31, 248, 31, 248, 15, 48, 14, 0, 29, 128, 59, 192, 115, 192, 225, 128, 192, 0 };


const unsigned char PROGMEM ICO_BLUETOOTH[] =
{ 7, 240, 15, 120, 31, 56, 31, 28, 31, 76, 25, 76, 28, 28, 30, 60, 30, 60, 28, 28, 25, 12, 31, 76, 31, 28, 31, 56, 15, 248, 7, 240 };

const unsigned char PROGMEM ICO_BLUETOOTH_OFF[] =
{ 7, 243, 15, 255, 31, 62, 31, 28, 31, 124, 25, 124, 28, 252, 31, 252, 31, 188, 31, 28, 31, 12, 31, 76, 63, 28, 127, 56, 239, 248, 199, 240 };

const unsigned char PROGMEM ICO_UP[] =
{ 0, 96, 0, 0, 240, 0, 1, 248, 0, 3, 252, 0, 7, 254, 0, 15, 255, 0, 31, 255, 128, 63, 255, 192, 7, 254, 0, 3, 252, 0, 3, 252, 0, 0, 0, 0, 3, 252, 0, 3, 252, 0, 3, 252, 0, 0, 0, 0, 3, 252, 0, 3, 252, 0, 0, 0, 0, 3, 252, 0}
;
const unsigned char PROGMEM ICO_DOWN[] =
{ 3, 252, 0, 0, 0, 0, 3, 252, 0, 3, 252, 0, 0, 0, 0, 3, 252, 0, 3, 252, 0, 3, 252, 0, 0, 0, 0, 3, 252, 0, 3, 252, 0, 7, 254, 0, 63, 255, 192, 31, 255, 128, 15, 255, 0, 7, 254, 0, 3, 252, 0, 1, 248, 0, 0, 240, 0, 0, 96, 0}
;

const unsigned char PROGMEM ICO_DOOR_OPEN[] =
{ 0, 0, 0, 0, 0, 0, 1, 255, 224, 31, 254, 0, 1, 0, 32, 16, 2, 0, 1, 0, 32, 16, 2, 0, 1, 0, 32, 16, 2, 0, 1, 0, 32, 16, 2, 0, 12, 0, 32, 16, 0, 0, 24, 0, 32, 16, 0, 192, 56, 0, 32, 16, 0, 96, 127, 248, 32, 16, 127, 240, 63, 248, 32, 16, 127, 248, 24, 0, 32, 16, 0, 112, 12, 0, 32, 16, 0, 96, 0, 0, 32, 16, 0, 192, 1, 0, 32, 16, 2, 0, 1, 0, 32, 16, 2, 0, 1, 0, 32, 16, 2, 0, 1, 0, 32, 16, 2, 0, 1, 255, 224, 31, 254, 0, 0, 0, 0, 0, 0, 0 }
;

const unsigned char PROGMEM ICO_DOOR_CLOSE[] =
{ 0, 0, 0, 0, 0, 0, 0, 127, 248, 127, 248, 0, 0, 64, 8, 64, 8, 0, 0, 64, 8, 64, 8, 0, 0, 64, 8, 64, 8, 0, 0, 64, 8, 64, 8, 0, 0, 65, 8, 66, 8, 0, 0, 65, 136, 70, 8, 0, 0, 65, 200, 78, 8, 0, 0, 79, 232, 95, 200, 0, 0, 79, 232, 95, 200, 0, 0, 65, 200, 78, 8, 0, 0, 65, 136, 70, 8, 0, 0, 65, 8, 66, 8, 0, 0, 64, 8, 64, 8, 0, 0, 64, 8, 64, 8, 0, 0, 64, 8, 64, 8, 0, 0, 64, 8, 64, 8, 0, 0, 127, 248, 127, 248, 0, 0, 0, 0, 0, 0, 0 }
;

enum Screen {
  BOOT,
  MAIN,
  MESSAGE
};

class Display {

  public:
    Screen screen;
  
    Display();
    void setup();
    void bootScreen();
    void setBootProgress(int progress);
    void setBootMessage(String message);

    void mainScreen();
    void setMainWifi(bool on);
    void setMainBluetooth(bool on);
	void setMainPosition(int position);
	void setMainCall1(bool on);
	void setMainCall0(bool on);
	void setMainMove(int direction);
	void setMainDoor(bool open);

    void refreshData();

  private:
    Adafruit_SSD1306* tft;
    void bootMessage();
    void bootProgress();
	void mainWifi();
	void mainBluetooth();
	void mainPosition();
	void mainCall1();
	void mainCall0();
	void mainMove();
	void mainDoor();

	int boot_progress;
	String boot_message;
	bool main_wifiOn;
	bool main_bluetoothOn;
	bool main_call1;
	bool main_call0;
	int main_position;
	int main_direction;
	bool main_open;
    
};

#endif
