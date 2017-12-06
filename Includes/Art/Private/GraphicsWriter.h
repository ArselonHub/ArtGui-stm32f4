/*
 * GraphicsWriter.h
 *
 *  Created on: Mar 31, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_GRAPHICSWRITER_H_
#define SOURCE_ART_PRIVATE_GRAPHICSWRITER_H_

#include <Art/Math.h>
#include <Art/Rectangle.h>
#include <Art/Color.h>

namespace Art
{
	class Graphics;

	namespace Private
	{
		class GraphicsWriter
		{
		public:
			virtual void beginBlock(const Rectangle& box) = 0;
			virtual void endBlock() = 0;
			virtual void skipPixels(Word length) = 0;
			virtual void pushPixel(Word index, Word length, void* palette) = 0;
			virtual void pushBuffer(void* buffer, Word length, void* palette) = 0;
			friend class Graphics;
		};
	}
}

#endif /* SOURCE_ART_PRIVATE_GRAPHICSWRITER_H_ */
