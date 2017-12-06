#ifndef ART_SIZE_H
#define ART_SIZE_H

#include <Art/Types.h>

namespace Art
{
	class Size
	{
	public:
		Size();
		Size(const Size& size);
		Size(Word width, Word height);
		void assign(Word  width, Word height);
		void adjust(Word dx, Word dy);
		void adjustHeight(Word delta);
		void adjustWidth(Word delta);
		Word height() const;
		Word width() const;
		void setHeight(Word height);
		void setWidth(Word width);

	private:
		Short m_width;
		Short m_height;
	};

	inline Size::Size()
	{
		m_width = 0;
		m_height = 0;
	}

	inline Size::Size(const Size& size)
	{
		m_width = size.m_width;
		m_height = size.m_height;
	}

	inline Size::Size(Word width, Word height)
	{
		m_width = width;
		m_height = height;
	}

	inline void Size::assign(Word width, Word height)
	{
		m_width = width;
		m_height = height;
	}

	inline Word Size::height() const
	{
		return m_height;
	}

	inline void Size::setHeight(Word height)
	{
		m_height = height;
	}

	inline Word Size::width() const
	{
		return m_width;
	}

	inline void Size::adjust(Word dx, Word dy)
	{
		m_width += dx;
		m_height += dy;
	}

	inline void Size::adjustHeight(Word delta)
	{
		m_height += delta;
	}

	inline void Size::adjustWidth(Word delta)
	{
		m_width += delta;
	}

	inline void Size::setWidth(Word width)
	{
		m_width = width;
	}
}

#endif
