#ifndef WG12864_H
#define WG12864_H

#include <core.h>
#include <ui\GraphicsBuffer.h>

#define KS108_ACTIVATE		0x3F
#define KS108_INACTIVATE	0x3E
#define KS108_SETY			0x40
#define KS108_SETX			0xB8
#define KS108_SETL			0xC0

class WG12864 : public GraphicsBuffer
{
protected:
	Pin rst;
	Pin e;
	Pin di;
	Pin rw;
	Pin cs1;
	Pin cs2;
	PinStrip data;

	virtual void setPixelInternal(Short x, Short y, UInt color);
	void stimulate();
public:
	__packed Byte	buffer[1024];	// 16 * 64

	void init(Byte flags = 0);

	void setX(Byte x) { writeCmd(KS108_SETX | x); }
	void setY(Byte y) { writeCmd(KS108_SETY | y); }
	void setL(Byte l) { writeCmd(KS108_SETL | l); }
	void setResetPin(Pinix value) { rst.init(value, PC_OUTPUT, 1); }
	void setEnablePin(Pinix value) { e.init(value, PC_OUTPUT, 0); }
	void setDIPin(Pinix value) { di.init(value, PC_OUTPUT, 0); }
	void setRWPin(Pinix value) { rw.init(value, PC_OUTPUT, 0); }
	void setCS1Pin(Pinix value) { cs1.init(value, PC_OUTPUT, 0); }
	void setCS2Pin(Pinix value) { cs2.init(value, PC_OUTPUT, 0); }
	void setDataPins(Pinix value) { data.init(value, 8); }
	void setDataPins(const Pinix * pins) { data.init(pins); }

	void startReading();
	void startWriting();
	void setActive(Bool value);

	void waitReady();
	void reset();
	void open();
	void selectController(Word index);
	void writeData(Byte data);
	void writeCmd(Byte cmd);
	virtual void update();
	virtual void clear();
};

#endif
