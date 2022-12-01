#ifndef _CFB_LED_H_
#define _CFB_LED_H_
#include<Arduino.h>

class CFB_led
{
	public:
		CFB_led(int pin);
		void acender();
		void apagar();
		void acender_t(int tmp);
		void apagar_t(int tmp);
		void piscar(int tmp);
	 private:
        int pino_led;
};
#endif