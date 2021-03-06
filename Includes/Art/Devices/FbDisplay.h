/*
 * FbDisplay.h
 *
 *  Created on: Mar 27, 2017
 *      Author: denizcan
 */

#ifndef ART_DEVICES_FBDISPLAY_H_
#define ART_DEVICES_FBDISPLAY_H_

#include <Art/Display.h>

namespace Art
{
	class FbDisplay : public Display
	{
	public:
		FbDisplay();
		virtual ~FbDisplay();
		virtual Graphics* beginUpdate();
		virtual void endUpdate(Graphics* g);
		virtual Graphics* createGraphics();

		void* frontBuffer() const;
		void* backBuffer() const;

		void setBackBuffer(void* value);
		void setFrontBuffer(void* value);
		virtual Word pitch() = 0;

	private:
		virtual void updateFrameBuffer() = 0;

		void*	m_frontBuffer;
		void*	m_backBuffer;
	};

	inline void FbDisplay::setBackBuffer(void* value)
	{
		m_backBuffer = value;
	}

	inline void FbDisplay::setFrontBuffer(void* value)
	{
		m_frontBuffer = value;
	}

	inline void* FbDisplay::frontBuffer() const
	{
		return m_frontBuffer;
	}

	inline void* FbDisplay::backBuffer() const
	{
		return m_backBuffer;
	}


} /* namespace Art */

#endif /* SOURCE_ART_DEVICES_FBDISPLAY_H_ */
