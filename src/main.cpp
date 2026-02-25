#include <Arduino.h>
#include <GxEPD2_BW.h> // Or GxEPD2_3C for 3-color
#include <Adafruit_GFX.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// --- Pin Mapping for ESP32-C3 ---
// Adjust these pins based on your wiring
#define EPD_CS     21
#define EPD_DC     4
#define EPD_RST    5
#define EPD_BUSY   6
#define EPD_SCK    8
#define EPD_MOSI   10

// --- Display Selection (Example: 1.54" 200x200) ---
// Find your specific constructor in GxEPD2_display_selection.h
GxEPD2_BW<GxEPD2_426_GDEQ0426T82, GxEPD2_426_GDEQ0426T82::HEIGHT> display(GxEPD2_426_GDEQ0426T82(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void helloWorld() {
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds("Hello C3", 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = (display.width() - tbw) / 2;
  uint16_t y = (display.height() + tbh) / 2;
  
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print("Hello C3");
  } while (display.nextPage());
}

void setup() {
  Serial.begin(115200);
  
  // Custom SPI for ESP32-C3 (if standard SPI doesn't work)
  SPI.begin(EPD_SCK, -1, EPD_MOSI, EPD_CS); 
  
  display.init(115200);
  helloWorld();
}

void loop() {
  // Deep sleep recommended for e-paper
}
