/*
 * MouseEvent.h
 *
 *  Created on: Dec 26, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_MOUSEEVENTARGS_H_
#define SOURCE_ART_MOUSEEVENTARGS_H_

#include <Art/Point.h>

namespace Art
{

	enum MouseButton
	{
		MouseButtonNone,
		MouseButtonLeft,
		MouseButtonRight,
		MouseButtonMiddle
	};
	ENUMFLAGS(MouseButton);

	class MouseEventArgs
	{
	public:
		MouseEventArgs(MouseButton buttons, const Point& location);
		MouseButton buttons() const;
		const Point& location() const;
		void setLocation(const Point& value);
		void setButtons(const MouseButton value);
	private:
		Point		m_location;
		MouseButton	m_buttons;
	};

	inline MouseButton MouseEventArgs::buttons() const
	{
		return m_buttons;
	}

	inline const Point& MouseEventArgs::location() const
	{
		return m_location;
	}

	inline MouseEventArgs::MouseEventArgs(MouseButton buttons,
			const Point& location)
	{
		m_buttons = buttons;
		m_location = location;
	}

	inline void MouseEventArgs::setLocation(const Point& value)
	{
		m_location = value;
	}

	inline void MouseEventArgs::setButtons(const MouseButton value)
	{
		m_buttons = value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_MOUSEEVENTARGS_H_ */
