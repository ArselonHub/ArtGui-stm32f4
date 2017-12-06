/*
 * CdiGraphicsRgb565.h
 *
 * Command Data Interface Graphics for RGB565 Interface
 *
 *  Created on: Oct 15, 2016
 *      Author: denizcan
 */

#ifndef ART_LCDGRAPHICS_H_
#define ART_LCDGRAPHICS_H_

#include <Art/Graphics.h>
#include <Art/LcdInterface.h>

namespace Art
{
	namespace Private
	{
		class CdiGraphicsRgb565 : public Graphics
		{
		public:
			LcdInterface* interface() const;
			void setInterface(LcdInterface* interface);

			DisplayOrientation displayOrientation();
			void setDisplayOrientation(DisplayOrientation value);
		private:
			enum WriteDirection
			{
				WriteDirectionHorizontal,
				WriteDirectionVertical
			};

			virtual void setWindow(Rectangle r) = 0;
			virtual void setLocation(Word x, Word y) = 0;
			virtual void setWriteDirection(WriteDirection value) = 0;

			virtual void drawBitmap1BOnSurface(void* buffer, const Rectangle& box);
			virtual void fillSurfaceRectangle(Rectangle& box);
			virtual void setSurfacePixel(Word x, Word y, Color color);
			virtual void drawSurfaceLine(Word x0, Word y0, Word x1, Word y1);

			LcdInterface* m_interface;
			DisplayOrientation m_displayOrientation;

		};

		inline LcdInterface* CdiGraphicsRgb565::interface() const
		{
			return m_interface;
		}

		inline void CdiGraphicsRgb565::setInterface(LcdInterface* interface)
		{
			m_interface = interface;
		}

		inline DisplayOrientation CdiGraphicsRgb565::displayOrientation()
		{
			return m_displayOrientation;
		}

		inline void CdiGraphicsRgb565::setDisplayOrientation(DisplayOrientation value)
		{
			m_displayOrientation = value;
		}
	}

} /* namespace Art */

#endif /* SOURCE_ART_LCDGRAPHICS_H_ */
