/*
 * ColorT.h
 *
 *  Created on: Apr 6, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_COLOR_H_
#define SOURCE_ART_COLOR_H_

#include <Art/Types.h>

namespace Art
{

	enum StandardColor
	{
		StandardColorTransparent,
		StandardColorBlack,
		StandardColorWhite,
		StandardColorMediumGray,
		StandardColorLightGray,
		StandardColorLightLightGray,
		StandardColorRed,
		StandardColorGreen,
		StandardColorBlue,
		StandardColorCyan,
		StandardColorMagenta,
		StandardColorYellow,
		StandardColorDarkRed,
		StandardColorDarkGreen,
		StandardColorDarkBlue,
		StandardColorDarkCyan,
		StandardColorDarkMagenta,
		StandardColorDarkYellow
	};

	enum SystemColor
	{
		SystemColorWindowBackground,
		SystemColorWindowForeground,
		SystemColorWindowTitleBacground,
		SystemColorWindowTitleForeground,
	};

	enum ColorKind
	{
		ColorKindInvalid,
		ColorKindSystem,
		ColorKindArgb = 3
	};

	class Color
	{
	public:
		Color();
		Color (const UInt value);
		Color(const Color& value);
		Color(StandardColor standardColor);
		Color(Word red, Word green, Word blue);
		Color(Word red, Word green, Word blue, Word alpha);
		void setRgb(Word red, Word green, Word blue);
		void setRgb(Word red, Word green, Word blue, Word alpha);
		UWord toRgb565() const;
		UWord toRgb242() const;
		Bool isValid() const;
		Bool operator ==(const Color& r) const;
		Bool operator !=(const Color& r) const;
	private:
		UInt m_value;
	};

	inline Color::Color(Word red, Word green, Word blue)
	{
		setRgb(red, green, blue);
	}

	inline Color::Color(Word red, Word green, Word blue, Word alpha)
	{
		setRgb(red, green, blue, alpha);
	}

	inline Color::Color()
	{
		m_value = 0;
	}

	inline Color::Color(const Color& value)
	{
		m_value = value.m_value;
	}

	inline Bool Color::isValid() const
	{
		return (m_value & 0x30000000);
	}

	inline Bool Color::operator ==(const Color& r) const
	{
		return m_value == r.m_value;
	}

	inline Color::Color(const UInt value)
	{
		m_value = value | 0x30000000;
	}


	inline Bool Color::operator !=(const Color& r) const
	{
		return m_value != r.m_value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_COLOR_H_ */
