#include "TFTLib.h"

Display::Display() {
  boot_progress = 0;
  boot_message = "";
  main_wifiOn = false;
  main_bluetoothOn = false;
  main_position = -1;
  main_call1 = false;
  main_call0 = false;
  main_direction = 0;
  main_open = false;
}

void Display::setup() {
  tft = new Adafruit_SSD1306(TFT_MOSI, TFT_CLK, TFT_DC, TFT_RESET, TFT_CS);
  tft->begin(SSD1306_SWITCHCAPVCC);
}

void Display::bootScreen() {
  screen = BOOT;
  tft->clearDisplay();
  tft->setCursor(64-10,0);
  tft->setTextColor(WHITE);
  tft->setTextSize(1);
  tft->println("BOOT");
  tft->drawLine(0, 10, 128, 10, WHITE);
  tft->drawRect(10, 50,108,10, WHITE);
  tft->display();
  bootMessage();
  bootProgress();
}

void Display::setBootMessage(String message) {
  if (message != boot_message) {
    boot_message = message;
    bootMessage();
  }
}

void Display::setBootProgress(int progress) {
  if (boot_progress != progress) {
    boot_progress = progress;
    bootProgress();
  }
}

void Display::bootMessage() {
  if (screen != BOOT){
    return;
  }
  tft->fillRect(0,25,128,25, BLACK);
  tft->setCursor(1,25);
  tft->setTextColor(WHITE);
  tft->setTextSize(1);
  tft->println(boot_message);
  tft->display();
}

void Display::bootProgress() {
  if (screen != BOOT){
    return;
  }
  tft->fillRect(11,51,106,8, BLACK);
  tft->fillRect(11,51,106*boot_progress/100,8, WHITE);
  tft->display();
}

void Display::mainScreen() {
 screen = MAIN;
 tft->clearDisplay();
  tft->setCursor(0,3);
  tft->setTextColor(WHITE);
  tft->setTextSize(1);
  tft->println("Elevator");
  tft->drawLine(0, 18, 128, 18, WHITE);
  tft->drawLine(88, 0, 88, 18, WHITE);
  tft->drawLine(108, 0, 108, 18, WHITE);
  tft->fillRoundRect(2, 22, 8, 40, 4, BLACK);
  tft->drawRoundRect(2, 22, 8, 40, 4, WHITE);
  tft->drawLine(10, 25, 16, 25, WHITE);
  tft->drawLine(10, 25 + 33, 16, 25 + 33, WHITE);
  tft->drawLine(32, 18, 32, 64, WHITE);
  tft->drawLine(82, 18, 82, 44, WHITE);
  tft->drawLine(32, 44, 128, 44, WHITE);
  tft->setCursor(18, 25 - 3);
  tft->print("1");
  tft->setCursor(18, 25 + 33 - 3);
  tft->print("0");
  tft->display();
  mainWifi();
  mainBluetooth();
  mainPosition();
  mainCall1();
  mainCall0();
  mainMove();
  mainDoor();
}

void Display::mainWifi() {
	if (screen != MAIN) {
		return;
	}
	tft->fillRect(90, 0, 16, 16, BLACK);
	if (main_wifiOn) {
		tft->drawBitmap(90, 0, ICO_WIFI, ICO_WIDTH, ICO_HEIGHT, 1);
	}
	else {
		tft->drawBitmap(90, 0, ICO_WIFI_OFF, ICO_WIDTH, ICO_HEIGHT, 1);
	}
	tft->display();
}

void Display::mainBluetooth() {
	if (screen != MAIN) {
		return;
	}
	tft->fillRect(110, 0, 16, 16, BLACK);
	if (main_bluetoothOn) {
		tft->drawBitmap(110, 0, ICO_BLUETOOTH, ICO_WIDTH, ICO_HEIGHT, 1);
	}
	else {
		tft->drawBitmap(110, 0, ICO_BLUETOOTH_OFF, ICO_WIDTH, ICO_HEIGHT, 1);
	}
	
	tft->display();
}

void Display::mainPosition() {
	if (screen != MAIN) {
		return;
	}
	tft->fillRoundRect(3, 23, 6, 38, 3, BLACK);
	tft->fillCircle(6, 25 + (33 * main_position / 100), 3, WHITE);
	tft->display();
}

void Display::mainCall0() {
	if (screen != MAIN) {
		return;
	}
	//16, 25 - 3
	int color = BLACK;
	if (main_call1) {
		color = WHITE;
	}
	tft->fillCircle(27, 26+33, 2, color);
	tft->display();
}

void Display::mainCall1() {
	if (screen != MAIN) {
		return;
	}
	//16, 25 - 3
	int color = BLACK;
	if (main_call1) {
		color = WHITE;
	}
	tft->fillCircle(27, 26, 2, color);
	tft->display();
}

void Display::mainDoor() {
	if (screen != MAIN) {
		return;
	}

	tft->fillRect(34, 22, 46, 20, BLACK);
	if (main_open) {
		tft->drawBitmap(34, 22, ICO_DOOR_OPEN, 46, 20, WHITE);
	}
	else {
		tft->drawBitmap(34, 22, ICO_DOOR_CLOSE, 46, 20, WHITE);
	}
	tft->display();
}

void Display::setMainPosition(int position) {
	if (screen != MAIN) {
		return;
	}
	position = 100 - position;
	if (position > 100) {
		position = 100;
	}
	else if (position < -1) {
		position = -1;
	}
	if (position % 33 != main_position % 33) {
		main_position = position;
	}
	mainPosition();
}

void Display::mainMove() {
	if (screen != MAIN) {
		return;
	}
	// 16, 25 - 3
	tft->fillRect(10, 32, 20, 20, BLACK);
	
	if (main_direction > 0) {
		tft->drawBitmap(10, 32, ICO_UP, 20, 20, WHITE);
	}
	else if (main_direction < 0) {
		tft->drawBitmap(10, 32, ICO_DOWN, 20, 20, WHITE);
	}
	tft->display();
}

void Display::setMainWifi(bool on) {
	if (main_wifiOn != on) {
		main_wifiOn = on;
		mainWifi();
	}
}

void Display::setMainBluetooth(bool on) {
	if (main_bluetoothOn != on) {
		main_bluetoothOn = on;
		mainBluetooth();
	}
}

void Display::setMainCall1(bool on) {
	if (main_call1 != on) {
		main_call1 = on;
		mainCall1();
	}
}

void Display::setMainCall0(bool on) {
	if (main_call0 != on) {
		main_call0 = on;
		mainCall0();
	}
}

void Display::setMainMove(int direction) {
	if (direction != main_direction) {
		main_direction = direction;
		mainMove();
	}
}

void Display::setMainDoor(bool open) {
	if (open != main_open) {
		main_open = open;
		mainDoor();
	}
}

void Display::refreshData() {


}

