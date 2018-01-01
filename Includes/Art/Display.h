#ifndef ART_DISPLAY_H
#define ART_DISPLAY_H

#include <Art/Device.h>
#include <Art/Graphics.h>

namespace Art
{
	class Display : public Device
	{
	public:
		Display();
		virtual ~Display();

		virtual Graphics* beginUpdate() = 0;
		virtual void endUpdate(Graphics* g) = 0;
		virtual Size surfaceSize() = 0;
		Rotation rotation() const;
		Word setRotation(Rotation value);

	protected:
		virtual Word openDevice();

	private:
		virtual Word switchRotation(Rotation newValue);

		Rotation	m_rotation;
	};

	inline Rotation Display::rotation() const
	{
		return m_rotation;
	}

}

#endif
