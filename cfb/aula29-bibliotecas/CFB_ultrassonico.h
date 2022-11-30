#ifndef _CFB_ULTRASSONICO_H_
#define _CFB_ULTRASSONICO_H_

# include<Arduino.h>

class CFB_ultrassonico
{
	public:
	CFB_ultrassonico(int pt, int pe);
	double distancia_cm();
	private:
    int pino_trigger;
    int pino_echo;
};



#endif