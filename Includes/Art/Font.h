#ifndef FONT_H
#define FONT_H

#include <Art/Types.h>

#define PACKED

namespace Art
{
	typedef PACKED struct
	{
		enum Styles
		{
			StylesRegular 	= 0x00,
			StylesBold		= 0x01,
			StylesItalic	= 0x02,
			StylesUnderline = 0x04,
			StylesStrikeout	= 0x08,
			StylesFixed		= 0x10,
			StylesClear		= 0x20
		};
		
		typedef PACKED struct
		{
			UShort	width;
			UShort	offset;		
		} Character;

		UByte		version;	/// 0, might be used as version in future
		UByte		height;		/// ascent + descent, that character resides
		UByte		ascent;		/// distance from top to the bottom line of the characters, to line
		UByte		ascender;	/// distance from top to the top of the character
		UByte		size;		/// size of the characters excluding punctuation
		UByte		width;		/// average width
		Styles		styles;		/// italic, bold etc, 0 for now
		UByte		firstChar;
		UByte		lastChar;
		UByte		defaultChar;
		UByte		rfu0;
		UByte		rfu1;
		Character	characters[1];
	} Font;

	namespace Fonts
	{
		extern const Font* lerosG9();
	}
}

#endif
