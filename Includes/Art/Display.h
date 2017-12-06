#ifndef ART_DISPLAY_H
#define ART_DISPLAY_H

#include <Art/Graphics.h>

namespace Art
{
	class Display
	{
	public:
		Result open();
		virtual Graphics* beginUpdate() = 0;
		virtual void endUpdate(Graphics* g) = 0;
		virtual Size surfaceSize() = 0;
		virtual Graphics* createGraphics() = 0;
	private:
		virtual void openPort() = 0;
	};
}

#endif
