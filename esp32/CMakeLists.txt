# cmake_minimum_required(VERSION <specify CMake version here>)
project(esp32)

set(CMAKE_CXX_STANDARD 11)

add_executable(esp32
        Firmware/pins.h
        Firmware/TFTLib.cpp
        Firmware/TFTLib.h
        samples/Buzzer/Buzzer.ino
        "samples/CLOCK/Arduino Playground - DS1302_files/137477057-postmessagerelay.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/300lo.json"
        "samples/CLOCK/Arduino Playground - DS1302_files/_ate.track.config_resp"
        "samples/CLOCK/Arduino Playground - DS1302_files/addthis_widget.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/animation.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/arduino-icons.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/arduino_code_highlight.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/arduinoWide_SSO.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/burger_menu.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/button.5f64a1a5864e1229f84c8defd65341b4.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/cart.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/cb=gapi(1).loaded_0"
        "samples/CLOCK/Arduino Playground - DS1302_files/cb=gapi.loaded_0"
        "samples/CLOCK/Arduino Playground - DS1302_files/cb=gapi.loaded_1"
        "samples/CLOCK/Arduino Playground - DS1302_files/cDyyloiRSzM.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/common.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/count.json"
        "samples/CLOCK/Arduino Playground - DS1302_files/custom.modernizr.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/DS1302.jpg"
        "samples/CLOCK/Arduino Playground - DS1302_files/ds1302.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/facebook.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/fastbutton.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/fonts.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/footer.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/footer.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/foundation.min.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/foundation2.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/ga.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/global_user_profile.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/gplus.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/header.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/header.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-facebook.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-flickr.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-github.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-gplus.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-instagram.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-twitter.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon-youtube.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon_geolocation.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/icon_quotes.svg"
        "samples/CLOCK/Arduino Playground - DS1302_files/jquery-1.10.2.min.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/lH1ibRl5GKq.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/like.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/loader.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/newsletter-modal.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/newsletter-modal.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/Nh1oH0K63yz.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/pinit.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/pinterest.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/plusone.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/postmessageRelay.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/rpc_shindig_random.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/rs=AGLTcCMLoZSVkvth9nKdYZ5ZOsEiyIZtmg"
        "samples/CLOCK/Arduino Playground - DS1302_files/saved_resource.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/sdk.js.téléchargement"
        "samples/CLOCK/Arduino Playground - DS1302_files/sh.d663e43787b663d5491cf753.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/tweet_button.2e798283373a8137c24e277b9b9620d6.en.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/twitter.png"
        "samples/CLOCK/Arduino Playground - DS1302_files/typeplate.css"
        "samples/CLOCK/Arduino Playground - DS1302_files/widget_iframe.2e798283373a8137c24e277b9b9620d6.html"
        "samples/CLOCK/Arduino Playground - DS1302_files/widgets.js.téléchargement"
        samples/CLOCK/CLOCK.ino/CLOCK.ino.ino
        samples/CLOCK/DS1302RTC/DS1302RTC/examples/DS1302_LCD/DS1302_LCD.ino
        samples/CLOCK/DS1302RTC/DS1302RTC/examples/DS1302_RAM_Demo/DS1302_RAM_Demo.ino
        samples/CLOCK/DS1302RTC/DS1302RTC/examples/DS1302_Serial/DS1302_Serial.ino
        samples/CLOCK/DS1302RTC/DS1302RTC/examples/SetSerial/SetSerial.ino
        samples/CLOCK/DS1302RTC/DS1302RTC/DS1302RTC.cpp
        samples/CLOCK/DS1302RTC/DS1302RTC/DS1302RTC.h
        samples/CLOCK/DS1302RTC/DS1302RTC/keywords.txt
        samples/CLOCK/DS1302RTC/DS1302RTC/README.TXT
        "samples/CLOCK/Arduino Playground - DS1302.html"
        samples/CLOCK/DS1302RTC.zip
        samples/CLOCK/Streaming5.zip
        samples/CLOCK/Time-master.zip
        samples/DISTANCE/DISTANCE.ino
        samples/SD/SD/SD.ino
        "samples/SD/PINS Connections.png"
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/examples/bmp/bmp.pde
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/examples/bmp/violet.bmp
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/examples/test/test.pde
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/Adafruit_SSD1331.cpp
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/Adafruit_SSD1331.h
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/library.properties
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/license.txt
        samples/TFT/Adafruit_SSD1331_OLED_Driver_Library_for_Arduino/README.txt
        samples/TFT/TFT.ino/TFT.ino.ino
        samples/TFT/TFTLib/TFTLib.ino)
