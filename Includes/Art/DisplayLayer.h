#ifndef ART_DISPLAYLAYER_H
#define ART_DISPLAYLAYER_H

#include <Art/Mcu.h>
#include <Art/Rectangle.h>
#include <Art/Private/GraphicTypes.h>

namespace Art
{
	class DisplayLayer
	{
	public:
		DisplayLayer(LTDC_Layer_TypeDef* port);
		void setRectangle(const Rectangle& value);
		void setBuffer(void* buffer, ShortL pitch);
		void setPixelFormat(PixelFormat value);
		void enable();
		void disable();
	private:
		LTDC_Layer_TypeDef*	port;
	};
	
	inline DisplayLayer::DisplayLayer(LTDC_Layer_TypeDef* port)
	{
		this->port = port;
	}


}

#endif

