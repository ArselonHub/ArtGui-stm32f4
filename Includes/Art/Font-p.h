#ifndef FONT_P_H
#define FONT_P_H

#include <ui/Font.h>

typedef __packed struct
{
	Byte		version;	/// 0, might be used as version in future
	Byte		height;		/// ascent + descent, that character resides
	Byte		ascent;		/// distance from top to the bottom line of the characters, to line 
	Byte		ascender;	/// distance from top to the top of the character
	Byte		size;		/// size of the characters excluding punctuation
	Byte		style;		/// italic, bold etc, 0 for now
	Byte		firstChar;
	Byte		lastChar;
	UShort		widthsOffset;
	UShort		bitmapOffsets[1];
} SmallFont;

typedef __packed struct
{
	Byte		version;	/// 0, might be used as version in future
	Byte		height;		/// ascent + descent, that character resides
	Byte		ascent;		/// distance from top to the bottom line of the characters, to line 
	Byte		ascender;	/// distance from top to the top of the character
	Byte		size;		/// size of the characters excluding punctuation
	Byte		style;		/// italic, bold etc, 0 for now
	Byte		firstChar;
	Byte		lastChar;
	UShort		widthsOffset;
	Byte		reserved0;
	Byte		reserved1;
	UInt		bitmapOffsets[1];
} LargeFont;


#endif
