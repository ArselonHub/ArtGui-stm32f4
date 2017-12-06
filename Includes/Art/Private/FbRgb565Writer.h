/*
 * FbRgb565Writer.h
 *
 *  Created on: Mar 31, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_FBRGB565WRITER_H_
#define ART_PRIVATE_FBRGB565WRITER_H_

#include <Art/Private/FbRgb565Graphics.h>

namespace Art
{
	namespace Private
	{

		class FbRgb565Writer : public GraphicsWriter
		{
		public:
			FbRgb565Writer(FbRgb565Graphics* graphics);
			//virtual ~FbRgb565Writer();
			virtual void beginBlock(const Rectangle& box);
			virtual void endBlock();
			virtual void skipPixels(Word length);
			virtual void pushPixel(Word index, Word length, void* palette);
			virtual void pushBuffer(void* buffer, Word length, void* palette);
		private:
			void step(Word count);
			Word skip(Word length);

			typedef UShort Pixel;
			Pixel*		m_pointer;
			Word		m_phaseLength;
			Word		m_pixelPitch;
			Word		m_linePitch;
			Word		m_activeLength;
			Word		m_skipLength;
			FbRgb565Graphics*	m_graphics;
		};


	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_FBRGB565WRITER_H_ */
