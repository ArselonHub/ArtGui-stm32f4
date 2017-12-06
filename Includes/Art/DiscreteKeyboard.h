#ifndef ART_DISCRETEKEYBOARD_H
#define ART_DISCRETEKEYBOARD_H

#include <Art/Timer.h>
#include <Art/Pin.h>
#include <Art/Keyboard.h>
#include <Art/KeyEvent.h>

namespace Art
{
	struct DiscreteKeyboardMapping
	{
		Pin* pin;
		Key key;
	};
	
	class DiscreteKeyboard : Keyboard
	{
	public:
		DiscreteKeyboard();
		DiscreteKeyboard(const DiscreteKeyboardMapping* mapping, UWord mapSize);
		void setMapping(const DiscreteKeyboardMapping* mapping, UWord mapSize);
		void open();		
	private:
		const DiscreteKeyboardMapping* mapping;
		Timer	timer;
		UShort  		change;
		UShort			status;
		Byte			iteration;
		Byte			mapLength;

		void handleTimerTick(void* sender);
	};

}

#endif
