/*
 * ImageA.h
 *
 *  Created on: Oct 12, 2016
 *      Author: denizcan
 */

#ifndef ART_IMAGEA_H_
#define ART_IMAGEA_H_

#include <Art/Private/GraphicsWriter.h>

namespace Art
{
	class Image
	{
	public:
		virtual ~Image();
		Word	width();
		Word	height();
		const Size& size() const;
	protected:
		Image(const Size& size);
		void setSize(const Size& value);
	private:
		Size	m_size;

		virtual void pushOn(Private::GraphicsWriter* writer, const Rectangle& box,
				const Color& background) const = 0;
		friend class Graphics;
	};

	inline Image::Image(const Size& size)
	{
		m_size = size;
	}

	inline Word Image::width()
	{
		return m_size.width();
	}

	inline Word Image::height()
	{
		return m_size.height();
	}

	inline const Size& Image::size() const
	{
		return m_size;
	}

	inline void Image::setSize(const Size& value)
	{
		m_size = value;
	}
} /* namespace Art */

#endif /* SOURCE_ART_IMAGEA_H_ */
