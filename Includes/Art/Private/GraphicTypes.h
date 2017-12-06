/*
 * GraphicTypes.h
 *
 *  Created on: Jan 27, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_GRAPHICTYPES_H_
#define ART_PRIVATE_GRAPHICTYPES_H_

#include <Art/Types.h>

namespace Art
{
	enum Alignment
	{
		AlignLeft 		= 0x00,
		AlignHCenter 	= 0x01,
		AlignRight		= 0x02,
		AlignTop		= 0x00,
		AlignVCenter	= 0x04,
		AlignBottom		= 0x08,
		AlignCenter		= 0x01 | 0x04
	};
	ENUMFLAGS(Alignment)

	enum DisplayOrientation
	{
		DisplayOrientationLandscape,
		DisplayOrientationPortrate,
		DisplayOrientationLandscapeUpSideDown,
		DisplayOrientationPortrateUpSideDown
	};

	enum Rotation
	{
		Rotation0,
		Rotation90,
		Rotation180,
		Rotation270
	};

	enum PixelFormat
	{
		PixelFormatARGB8888,
		PixelFormatRGB888,
		PixelFormatRGB565,
		PixelFormatARGB1555,
		PixelFormatARGB4444,
		PixelFormatL8,
		PixelFormatAL44,
		PixelFormatAL88
	};

	enum Quadrant
	{
		Quadrant1,
		Quadrant2,
		Quadrant3,
		Quadrant4
	};

}



#endif /* SOURCE_ART_PRIVATE_GRAPHICTYPES_H_ */
