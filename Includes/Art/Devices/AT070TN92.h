#ifndef ART_AT070TN92_H
#define ART_AT070TN92_H

#include <Art/Devices/FbDisplay.h>

namespace Art
{
	class AT070TN92 : public FbDisplay
	{
	public:
		virtual ~AT070TN92();
		virtual Size surfaceSize();
		virtual Word pitch();

	private:
		virtual void updateFrameBuffer();
		virtual void openPort();
	};
}

#endif
