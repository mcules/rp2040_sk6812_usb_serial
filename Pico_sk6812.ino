#include <Adafruit_NeoPixel.h>
#include <Adafruit_TinyUSB.h>
#include <ArduinoJson.h>

#define LED_PIN   28 // pin which connects to led stripe
#define LED_NUM   10 // Number of pixels in led stripe
#define LED_TYPES NEO_GRBW // Type of LEDs (NEO_GRBW / NEO_GRB)
#define LED_SPEED NEO_KHZ800 // communication speed to leds
#define SERIAL_SPEED 115200 // Speed of serial interface

Adafruit_NeoPixel pixels(LED_NUM, LED_PIN, LED_TYPES + LED_SPEED);
DynamicJsonDocument jsonDocument(10240);

void setup() {
  Serial.begin(SERIAL_SPEED); // Initialize serial port
  pixels.begin(); // Initialize NeoPixel strip object (REQUIRED)
  pixels.clear();
}

// get json data from serial usb
bool serial_get_json() {
  String jsonString = Serial.readStringUntil('\n'); // wait until \n is given
  jsonString.replace("\n", "NUL, 0");

  DeserializationError error = deserializeJson(jsonDocument, jsonString); // parsestring to json
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return false;
  }

  return true;
}

void loop() {
  if (Serial.available() > 0) { // serial is available
    if (serial_get_json()) { // got an json array on serial
      pixels.clear(); // Set all pixel colors to 'off'

      // iterate through all pixels
      for (JsonArray pixel : jsonDocument.as<JsonArray>()) {
        setPixelColor(pixel[0], pixel[1], pixel[2], pixel[3], pixel[4], pixel[5]);
      }
      
      pixels.show(); // Show pixels
    }
  }
}

// set colors and brightness for pixel
void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b,  uint8_t w, uint16_t brightness) {
  pixels.setPixelColor(n, (brightness*r/100), (brightness*g/100), (brightness*b/100), (brightness*w/100));
}