#ifndef MATRIXKEYBOARD_H
#define MATRIXKEYBOARD_H

#include <Art/Timer.h>
#include <Art/Keyboard.h>

namespace Art
{
	class MatrixKeyboard : public Keyboard
	{
	public:
		MatrixKeyboard();
		MatrixKeyboard(const void* config);
		void setConfiguration(const void* value) { config = (Byte*)value; }
		void open();

	private:
		Timer updateTimer;
		Byte* config;
		UInt accumulator;
		UInt states;
		UInt filters;
		Byte scanIndex;
		
		void handleUpdateTimerTick();
	};
}

#endif
