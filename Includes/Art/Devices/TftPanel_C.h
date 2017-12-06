#ifndef ART_TFTPANEL_H
#define ART_TFTPANEL_H

#include <Art/Types.h>
#include <Art/Display.h>

namespace Art
{
	typedef void (*LcdWriteIndex)(UInt value);
	typedef void (*LcdWriteRegister)(UInt index, UInt value);
	typedef void (*LcdWriteSingle)(UInt value);
	typedef UInt (*LcdReadSingle)();
	typedef void (*LcdWriteMultiple)(UInt value, Word length);
	typedef void (*LcdWriteBuffer)(void* buffer, Word length);

	class TftPanel_C : public Display
	{
	protected:
		LcdWriteIndex 		writeIndex;
		LcdWriteRegister	writeRegister;
		LcdWriteSingle		writeSingle;
		LcdWriteMultiple	writeMultiple;
		LcdWriteBuffer		writeBuffer;
		LcdReadSingle		readSingle;
		Bool dirtyWindow;
		Bool horizontal;

		void init();
		virtual Result configure() = 0;
	public:
		virtual Result open();

		void setWriteIndex(LcdWriteIndex value) { writeIndex = value; }
		void setWriteRegister(LcdWriteRegister value) { writeRegister = value; }
		void setWriteSingle(LcdWriteSingle value) { writeSingle = value; }
		void setWriteMultiple(LcdWriteMultiple value) { writeMultiple = value; }
		void setWriteBuffer(LcdWriteBuffer value) { writeBuffer = value; }	
		void setReadSingle(LcdReadSingle value) { readSingle = value; }
	};


	#define DEFINE_TFTPANEL_C(name)\
	class name : public TftPanel_C\
	{\
	public:\
		using Graphics::fillRectangle;\
		virtual void setPixel(Short x, Short y, Color color);\
		virtual void drawLine(Word x0, Word y0, Word x1, Word y1);\
		virtual void fillRectangle(Word left, Word top, Word right, Word bottom);\
	protected:\
		virtual Result configure();\
		virtual void drawBitmap1B(void* buffer, const Rectangle& box);\
	}
}

#endif
