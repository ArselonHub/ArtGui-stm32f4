#ifndef ART_DEVICES_ILI9341RGB_H
#define ART_DEVICES_ILI9341RGB_H

#include <Art/Devices/ILI9341Base.h>
#include <Art/Pin.h>
#include <Art/SpiMaster.h>
#include <Art/DisplayController.h>
#include <Art/Graphics.h>

namespace Art
{
	class ILI9341FbRgb565 : public ILI9341Base
	{
	public:
		void setDataSelectPin(Pin* value);
		void setSpiPort(SpiPort* value);
		void setSpiSelectPin(Pin* value);
		void setDisplayController(DisplayController* value);
		UInt minumumFrameBufferSize();
		UWord frameBufferPitch() const;
		void* frameBuffer() const;
		void setFrameBuffer(void* value);

		virtual Graphics* beginUpdate();
		virtual void endUpdate(Graphics* g);
		virtual Graphics* createGraphics();
		void setDoubleBuffered(Bool value);
	protected:
		virtual void executeCommand(UWord command);
		virtual void executeWrite(UWord command, const void* data, ShortL length);
		virtual void executeRead(UWord command, void* data, ShortL length);
		virtual void writeData(const void* data, ShortL length);
		virtual void writeByte(UWord value);
	private:
		virtual void openPort();

		Pin*			m_dataSelectPin;
		SpiMaster		m_spiMaster;
		DisplayController*	m_displayController;
		void*			m_frameBuffer;
		void* 			m_buffers[2];
		Word			m_frameIndex;
		Word			m_bufferSize;
	};

	inline void ILI9341FbRgb565::setDataSelectPin(Pin* value)
	{
		m_dataSelectPin = value;
	}

	inline void ILI9341FbRgb565::setSpiPort(SpiPort* value)
	{
		m_spiMaster.setPort(value);
	}

	inline void ILI9341FbRgb565::setSpiSelectPin(Pin* value)
	{
		m_spiMaster.setSelectPin(value);
	}

	inline void ILI9341FbRgb565::setDisplayController(DisplayController* value)
	{
		m_displayController = value;
	}

	inline void* ILI9341FbRgb565::frameBuffer() const
	{
		return m_frameBuffer;
	}

	inline UInt ILI9341FbRgb565::minumumFrameBufferSize()
	{
		return 320 * 240 * sizeof(UShort);
	}

	inline UWord ILI9341FbRgb565::frameBufferPitch() const
	{
		return 240 * sizeof(UShort);
	}

	inline void ILI9341FbRgb565::setFrameBuffer(void* value)
	{
		m_frameBuffer = value;
	}

	inline void ILI9341FbRgb565::setDoubleBuffered(Bool value)
	{
		if (value)
			m_frameIndex = 0;
		else
			m_frameIndex = -1;
	}

}

#endif
