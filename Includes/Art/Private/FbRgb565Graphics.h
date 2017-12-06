/*
 * MemorySurface.h
 *
 *  Created on: Oct 11, 2016
 *      Author: denizcan
 */

#ifndef ART_FBGRAPHICSRGB565_H_
#define ART_FBGRAPHICSRGB565_H_

#include <Art/Graphics.h>

namespace Art
{
	namespace Private
	{

		class FbRgb565Graphics : public Graphics
		{
		public:
			FbRgb565Graphics(const Size& size, Rotation rotation, void* buffer, Word pitch);
		private:
			void pushPixelValue(UWord value, Word length);
			virtual void drawBitmap1BOnSurface(void* buffer, const Rectangle& box,
					const Color& color, const Color& background);
			virtual void drawImageOnSurface(const Image* image, const Rectangle& box,
					const Color& background);
			virtual void fillSurfaceRectangle(Rectangle& box, const Color& color);
			virtual void setSurfacePixel(Word x, Word y, const Color& color);
			virtual void drawSurfaceLine(Word x0, Word y0, Word x1, Word y1, const Color& color);

			typedef UShort Pixel;
			Pixel*	m_topLeft;
			Word	m_linePitch;
			Word	m_pixelPitch;
			Rotation m_rotation;

			friend class FbRgb565Writer;
		};
	}

} /* namespace Art */

#endif /* SOURCE_ART_MEMORYSURFACE_H_ */
