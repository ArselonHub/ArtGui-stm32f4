#ifndef ART_DISPLAYCONTROLLER_H
#define ART_DISPLAYCONTROLLER_H

#include <Art/Types.h>
#include <Art/Pin.h>
#include <Art/Color.h>

namespace Art
{
	enum Polarity
	{
		PolarityActiveLow,
		PolarityActiveHigh
	};
	
	class DisplayController
	{
	public:
		DisplayController();
		void open();
	
		Word frameBufferpitch();
		void setFrameBufferPitch(Word value);
	
		void setFrameBuffer(void* value);	
		void setHSyncPolarity(Polarity value);
		void setVSyncPolarity(Polarity value);
		void setDataEnablePolarity(Polarity value);
		void setPixelClockPolarity(Polarity value);
		void setHSync(Int value);
		void setHBackPorch(Int value);
		Word hActiveArea();
		void setHActiveArea(Int value);
		void setHFrontPorch(Int value);
		void setVSync(Int value);
		void setVBackPorch(Int value);
		Word vActiveArea();
		void setVActiveArea(Int value);
		void setVFrontPorch(Int value);		
		void setBackgroundColor(const Color& value);

		void setRed0Pin(Pin* pin);
		void setRed1Pin(Pin* pin);
		void setRed2Pin(Pin* pin);
		void setRed3Pin(Pin* pin);
		void setRed4Pin(Pin* pin);
		void setRed5Pin(Pin* pin);
		void setRed6Pin(Pin* pin);
		void setRed7Pin(Pin* pin);
		void setGreen0Pin(Pin* pin);
		void setGreen1Pin(Pin* pin);
		void setGreen2Pin(Pin* pin);
		void setGreen3Pin(Pin* pin);
		void setGreen4Pin(Pin* pin);
		void setGreen5Pin(Pin* pin);
		void setGreen6Pin(Pin* pin);
		void setGreen7Pin(Pin* pin);
		void setBlue0Pin(Pin* pin);
		void setBlue1Pin(Pin* pin);
		void setBlue2Pin(Pin* pin);
		void setBlue3Pin(Pin* pin);
		void setBlue4Pin(Pin* pin);
		void setBlue5Pin(Pin* pin);
		void setBlue6Pin(Pin* pin);
		void setBlue7Pin(Pin* pin);
		void setClockPin(Pin* pin);
		void setDEPin(Pin* pin);
		void setHSyncPin(Pin* pin);
		void setVSyncPin(Pin* pin);
		
	private:
		void configurePins();
		void configureController();
		void configureLayer();
		void reconfigureController();
		void reconfigureLayer();
	
		void* 		m_frameBuffer;
		Word 		m_frameBufferPitch;
		Color		m_backgroundColor;
		Bool		m_active;
		Polarity	m_hSyncPolarity;
		Polarity	m_vSyncPolarity;
		Polarity	m_dePolarity;
		Polarity	m_clockPolarity;
		
		Word		hSync_;
		Word		hBackPorch_;
		Word		hActiveArea_;
		Word		hFrontPorch_;
		Word		vSync_;
		Word		vBackPorch_;
		Word		vActiveArea_;
		Word		vFrontPorch_;
	
		Pin*	red0Pin_;
		Pin*	red1Pin_;
		Pin*	red2Pin_;
		Pin*	red3Pin_;
		Pin*	red4Pin_;
		Pin*	red5Pin_;
		Pin*	red6Pin_;
		Pin*	red7Pin_;
		Pin*	green0Pin_;
		Pin*	green1Pin_;
		Pin*	green2Pin_;
		Pin*	green3Pin_;
		Pin*	green4Pin_;
		Pin*	green5Pin_;
		Pin*	green6Pin_;
		Pin*	green7Pin_;
		Pin*	blue0Pin_;
		Pin*	blue1Pin_;
		Pin*	blue2Pin_;
		Pin*	blue3Pin_;
		Pin*	blue4Pin_;
		Pin*	blue5Pin_;
		Pin*	blue6Pin_;
		Pin*	blue7Pin_;
		Pin*	clockPin_;
		Pin*	dePin_;
		Pin*	hSyncPin_;
		Pin*	vSyncPin_;
	};
	
	inline Word DisplayController::frameBufferpitch()
	{
		return m_frameBufferPitch;
	}

	inline Word DisplayController::hActiveArea()
	{
		return hActiveArea_;
	}
	
	inline Word DisplayController::vActiveArea()
	{
		return vActiveArea_;
	}

	inline void DisplayController::setRed0Pin(Pin* value)
	{
		red0Pin_ = value;
	}		
	
	inline void DisplayController::setRed1Pin(Pin* value)
	{
		red1Pin_ = value;
	}		
	
	inline void DisplayController::setRed2Pin(Pin* value)
	{
		red2Pin_ = value;
	}		

	inline void DisplayController::setRed3Pin(Pin* value)
	{
		red3Pin_ = value;
	}		

	inline void DisplayController::setRed4Pin(Pin* value)
	{
		red4Pin_ = value;
	}		

	inline void DisplayController::setRed5Pin(Pin* value)
	{
		red5Pin_ = value;
	}			

	inline void DisplayController::setRed6Pin(Pin* value)
	{
		red6Pin_ = value;
	}		

	inline void DisplayController::setRed7Pin(Pin* value)
	{
		red7Pin_ = value;
	}		

	inline void DisplayController::setGreen0Pin(Pin* value)
	{
		green0Pin_ = value;
	}		
	
	inline void DisplayController::setGreen1Pin(Pin* value)
	{
		green1Pin_ = value;
	}		
	
	inline void DisplayController::setGreen2Pin(Pin* value)
	{
		green2Pin_ = value;
	}		

	inline void DisplayController::setGreen3Pin(Pin* value)
	{
		green3Pin_ = value;
	}		

	inline void DisplayController::setGreen4Pin(Pin* value)
	{
		green4Pin_ = value;
	}		

	inline void DisplayController::setGreen5Pin(Pin* value)
	{
		green5Pin_ = value;
	}		

	inline void DisplayController::setGreen6Pin(Pin* value)
	{
		green6Pin_ = value;
	}		

	inline void DisplayController::setGreen7Pin(Pin* value)
	{
		green7Pin_ = value;
	}		

	inline void DisplayController::setBlue0Pin(Pin* value)
	{
		blue0Pin_ = value;
	}		
	
	inline void DisplayController::setBlue1Pin(Pin* value)
	{
		blue1Pin_ = value;
	}		
	
	inline void DisplayController::setBlue2Pin(Pin* value)
	{
		blue2Pin_ = value;
	}		

	inline void DisplayController::setBlue3Pin(Pin* value)
	{
		blue3Pin_ = value;
	}		

	inline void DisplayController::setBlue4Pin(Pin* value)
	{
		blue4Pin_ = value;
	}		

	inline void DisplayController::setBlue5Pin(Pin* value)
	{
		blue5Pin_ = value;
	}		

	inline void DisplayController::setBlue6Pin(Pin* value)
	{
		blue6Pin_ = value;
	}		

	inline void DisplayController::setBlue7Pin(Pin* value)
	{
		blue7Pin_ = value;
	}		

	inline void DisplayController::setClockPin(Pin* value)
	{
		clockPin_ = value;
	}		

	inline void DisplayController::setDEPin(Pin* value)
	{
		dePin_ = value;
	}		

	inline void DisplayController::setHSyncPin(Pin* value)
	{
		hSyncPin_ = value;
	}		

	inline void DisplayController::setVSyncPin(Pin* value)
	{
		vSyncPin_ = value;
	}		
	
	extern DisplayController* ltdc();

};

#endif
