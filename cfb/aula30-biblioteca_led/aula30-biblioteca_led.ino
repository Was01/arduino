#include <CFB_led.h>

#define pino_led 7

CFB_led led(pino_led);

void setup() {
 
}

void loop() {
  led.piscar(500);

}
