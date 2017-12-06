#ifndef ART_SAT050AT40_H
#define ART_SAT050AT40_H

#include <Art/Devices/FbDisplay.h>

namespace Art
{
	class AT050AT40 : public FbDisplay
	{
	public:
		virtual ~AT050AT40();
		virtual Size surfaceSize();
		virtual Word pitch();

	private:
		virtual void updateFrameBuffer();
		virtual void openPort();

	};

}

#endif
