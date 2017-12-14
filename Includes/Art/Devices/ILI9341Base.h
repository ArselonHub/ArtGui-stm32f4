#ifndef ART_DEVICES_ILI9341BASE_H
#define ART_DEVICES_ILI9341BASE_H

#include <Art/Display.h>

namespace Art
{
	class ILI9341Base : public Display
	{
	public:
		virtual ~ILI9341Base();
		void readDisplayIdentification(UInt& id);
		UWord readPowerMode();
		UWord readPixelFormat();
		UWord readImageFormat();
		UWord readID1();
		UWord readID2();
		void reset();
		void disable();
		void enable();
		virtual Size surfaceSize();
	protected:
		//HACK Is this correct name?
		void configurePanel();
		virtual void executeCommand(UWord command) = 0;
		virtual void executeWrite(UWord command, const void* data, ShortL length) = 0;
		virtual void executeRead(UWord command, void* data, ShortL length) = 0;
		virtual void writeData(const void* data, ShortL length) = 0;
		virtual void writeByte(UWord value) = 0;
	};
}

#endif
