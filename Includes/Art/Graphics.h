#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <Art/Color.h>
#include <Art/Font.h>
#include <Art/Rectangle.h>
#include <Art/String.h>
#include <Art/Private/GraphicTypes.h>
#include <Art/Private/GraphicsWriter.h>
#include <Art/Image.h>

namespace Art
{
	class Image;

	class Graphics
	{
	public:
		virtual ~Graphics();
		void drawString(const StringRef& s, const Font* font,
				Word x, Word y, const Color& color);
		void drawString(const StringRef& s, const Font* font,
				Word x, Word y, const Color& color, const Color& background);
		void drawString(const StringRef& s, const Font* font,
				const Rectangle& box, Alignment alignment,
				const Color& color);
		void drawString(const StringRef& s, const Font* font,
				const Rectangle& box, Alignment alignment,
				const Color& color, const Color& background);
		Size measureString(const StringRef& s, const Font* font);

		void drawImage(const Image* image, Word x, Word y);
		void drawImage(const Image* image, Word x, Word y, const Color& background);

		void drawRectangle(Word x, Word y, Word width, Word height, const Color& color);
		void drawRectangle(const Rectangle &r, const Color& color);


		void setPixel(Word x, Word y, const Color& color);
		void setPixel(const Point& pt, const Color& color);
		void fillRectangle(Word left, Word top, Word width, Word height, const Color& color);
		void fillRectangle(const Rectangle& r, const Color& color);
		void fillRoundRectangle(const Rectangle& r, Word radius, const Color& color);
		void fillRoundRectangle(const Rectangle& r, Word radius, const Color& color, const Color& background);

		void drawLine(const Point& pt0, const Point& pt1, const Color& color);
		void drawLine(Word x0, Word y0, Word x1, Word y1, const Color& color);

		void setOrigin(const Point& value);
		Rectangle clipRectangle();
	protected:
		Graphics(const Size& size);
		const Rectangle& surfaceBox() const;
		void setSurfaceOrigin(const Point& value);
		void setSurfaceBox(const Rectangle& value);
		void pushImageOn(const Image* image, const Rectangle& box,
				Private::GraphicsWriter* writer, const Color& background);

	private:
		const Font::Character* getFontCharacter(const Font* font, Char c);
		Word calcPushLength(Word length);

		virtual void drawBitmap1BOnSurface(void* buffer, const Rectangle& box,
				const Color& color, const Color& background) = 0;
		virtual void drawImageOnSurface(const Image* image, const Rectangle& box,
				const Color& background) = 0;
		virtual void fillSurfaceRectangle(const Rectangle& box, const Color& color) = 0;
		virtual void setSurfacePixel(Word x, Word y, const Color& color) = 0;
		virtual void drawSurfaceLine(Word x0, Word y0, Word x1, Word y1, const Color& color) = 0;

		Point 		m_origin;
		Point		m_surfaceOrigin;
		Rectangle	m_surfaceBox;

		friend class View;
		friend class Image;
	};

	inline const Art::Rectangle& Graphics::surfaceBox() const
	{
		return m_surfaceBox;
	}

	inline Rectangle Graphics::clipRectangle()
	{
		return m_surfaceBox.translated(m_surfaceOrigin);
	}

	inline void Graphics::setSurfaceBox(const Rectangle& value)
	{
		m_surfaceBox = value;
	}

	inline void Graphics::pushImageOn(const Image* image,
			const Rectangle& box,
			Private::GraphicsWriter* writer,
			const Color& background)
	{
		image->pushOn(writer, box, background);
	}
}

#endif
