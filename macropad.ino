
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BleKeyboard.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

BleKeyboard bleKeyboard("Hardik MacroPad", "DIY", 100);

const int buttons[] = {0, 1, 3, 6};
bool lastState[] = {HIGH, HIGH, HIGH, HIGH};

void showMessage(const char* action, const char* status) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("MACROPAD");
  display.setTextSize(1);
  display.println();
  display.print("Action: ");
  display.println(action);
  display.println();
  display.println(status);
  display.display();
}

void setup() {
  Serial.begin(115200);

  Wire.begin(8, 9);

  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) delay(10);
  }

  showMessage("Starting", "Bluetooth starting...");
  bleKeyboard.begin();
}

void loop() {
  if (!bleKeyboard.isConnected()) {
    showMessage("Waiting", "Pair via Bluetooth");
    delay(500);
    return;
  }

  for (int i = 0; i < 4; i++) {
    bool state = digitalRead(buttons[i]);

    if (lastState[i] == HIGH && state == LOW) {
      switch (i) {
        case 0:
          showMessage("COPY", "Ctrl + C");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('c');
          delay(100);
          bleKeyboard.releaseAll();
          break;

        case 1:
          showMessage("PASTE", "Ctrl + V");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('v');
          delay(100);
          bleKeyboard.releaseAll();
          break;

        case 2:
        showMessage("SCREENSHOT", "Win + Shift + S");
        bleKeyboard.press(KEY_LEFT_GUI);
        bleKeyboard.press(KEY_LEFT_SHIFT);
        bleKeyboard.press('s');
        delay(100);
        bleKeyboard.releaseAll();
        break;
        
        case 3:
          showMessage("REFRESH", "F5");
          bleKeyboard.press(KEY_F5);
          delay(100);
          bleKeyboard.releaseAll();
          break;
      }
    }

    lastState[i] = state;
  }

  delay(20);
}
