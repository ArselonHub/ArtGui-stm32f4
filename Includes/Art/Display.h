#ifndef ART_DISPLAY_H
#define ART_DISPLAY_H

#include <Art/Graphics.h>

namespace Art
{
	class Display
	{
	public:
		virtual ~Display();
		Result open();
		virtual Graphics* beginUpdate() = 0;
		virtual void endUpdate(Graphics* g) = 0;
		virtual Size surfaceSize() = 0;
		Rotation rotation() const;
		void setRotation(Rotation value);
	private:
		virtual void openPort() = 0;

		Rotation	m_rotation;
	};

	inline Rotation Display::rotation() const
	{
		return m_rotation;
	}

	inline void Display::setRotation(Rotation value)
	{
		m_rotation = value;
	}

}

#endif
