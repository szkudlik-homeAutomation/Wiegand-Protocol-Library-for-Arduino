#ifndef _WIEGAND_H
#define _WIEGAND_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class WIEGAND {

public:
	WIEGAND();
	void begin();
	void begin(uint8_t pinD0, uint8_t pinD1);
	void begin(uint8_t pinD0, uint8_t pinIntD0, uint8_t pinD1, uint8_t pinIntD1);
	bool available();
	uint32_t  getCode();
	uint8_t getWiegandType();
	
private:
	static void ReadD0();
	static void ReadD1();
	static bool DoWiegandConversion ();
	static uint32_t  GetCardId (volatile uint32_t  *codehigh, volatile uint32_t  *codelow, char bitlength);
	
	static volatile uint32_t  	_cardTempHigh;
	static volatile uint32_t  	_cardTemp;
	static volatile uint32_t  	_lastWiegand;
	static volatile uint8_t		_bitCount;
	static uint8_t				_wiegandType;
	static uint32_t 	_code;
};

#endif
