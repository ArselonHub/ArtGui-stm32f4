/*
 * Button.h
 *
 *  Created on: Jan 6, 2017
 *      Author: denizcan
 */

#ifndef ART_BUTTON_H_
#define ART_BUTTON_H_

#include <Art/Control.h>
#include <Art/Image.h>

namespace Art
{
	class Button : public Control
	{
	public:
		Button();
		virtual ~Button();

		Short cornerRadius() const;
		void setCornerRadius(Short cornerRadius);
		Color downBackgroundColor() const;
		void setDownBackgroundColor(const Color& downBackgroundColor);

		Image* image() const;
		void setImage(Image* value);

		Signal<void*> onClick() SIGNAL;
	protected:
		virtual void doClick();
		virtual void paint(Graphics* g);
		virtual void doMouseDown(MouseEventArgs* args);
		virtual void doMouseMove(MouseEventArgs* args);
		virtual void doMouseUp(MouseEventArgs* args);

	private:
		Image*	m_image;
		Color	m_downBackgroundColor;
		Short	m_cornerRadius;
		Bool 	m_down: 1;
	};

	inline Short Button::cornerRadius() const
	{
		return m_cornerRadius;
	}

	inline void Button::setCornerRadius(Short cornerRadius)
	{
		m_cornerRadius = cornerRadius;
	}

	inline Color Button::downBackgroundColor() const
	{
		return m_downBackgroundColor;
	}

	inline Image* Button::image() const
	{
		return m_image;
	}

} /* namespace Art */

#endif /* SOURCE_ART_BUTTON_H_ */
