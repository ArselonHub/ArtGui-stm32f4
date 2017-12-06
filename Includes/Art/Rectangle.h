#ifndef ART_RECTANGLE_H
#define ART_RECTANGLE_H

#include <Art/Math.h>
#include <Art/Point.h>
#include <Art/Size.h>

namespace Art
{
	class Rectangle
	{	
	public:
		Rectangle();
		Rectangle(const Point& pt0, const Point& pt1);
		Rectangle(const Point& location, const Size& size);
		Rectangle(const Size& size);
		Rectangle(Word width, Word height);
		Rectangle(Word left, Word top, Word width, Word height);

		void assign(Word left, Word top, Word width, Word height);

		Word bottom() const;
		Word left() const;
		Word right() const;
		Word top() const;

		Word width() const;
		Word height() const;
		Size size() const;
		Point leftTop() const;
		Point location() const;
		Point rightBottom() const;
		Bool hasPoint(const Word x, const Word y) const;
		Bool hasPoint(const Point& p) const;
		Bool hasIntersection(const Rectangle& r) const;
		Rectangle& intersect(const Rectangle& r);
		Bool isValid() const;
		Bool isInvalid() const;
		void moveBy(Word deltaX, Word deltaY);
		void moveLeftBy(Word delta);
		void moveTopBy(Word delta);
		void moveBottomBy(Word delta);
		void moveRightBy(Word delta);

		Rectangle translated(const Word dx, const Word dy) const;
		Rectangle translated(const Point& p) const;
		Rectangle withOrigin(const Word x, const Word y) const;
		Rectangle withOrigin(const Point& p) const;
		Rectangle withSize(const Word w, const Word h) const;
		Rectangle intersection(const Rectangle& r) const;
		Rectangle leftRectangle(const Word width) const;
		Rectangle rightRectangle(const Word width) const;
		Rectangle topRectangle(const Word height) const;
		Rectangle bottomRectangle(const Word height) const;
		void setBottom(Short bottom);
		void setLeft(Word left);
		void setRight(Word right);
		void setWidth(Word value);
		void setHeight(Word value);
		void setTop(Word top);
		void moveTo(const Word x, const Word y);
		void moveTo(const Point& p);
		void setOrigin(Word x, Word y);
		void setOrigin(const Point& p);
		void setSize(const Word width, const Word height);
		void setSize(const Size &value);
		void translate(Word dx, Word dy);
		void translate(const Point& p);
		void shrinkBy(Word dx, Word dy);
		void shrinkHorizontal(Word delta);
		void shrinkVertical(Word delta);

		Rectangle shrinked(Word dx, Word dy) const;
	private:
		Short m_left;
		Short m_top;
		Short m_right;
		Short m_bottom;
	};

	inline Rectangle::Rectangle()
	{
		m_left = 0;
		m_top = 0;
		m_right = 0;
		m_bottom = 0;
	}

	inline Rectangle::Rectangle(const Point& pt0, const Point& pt1)
	{
		m_left = pt0.x();
		m_top = pt0.y();
		m_right = pt1.x();
		m_bottom = pt1.y();
	}

	inline Rectangle::Rectangle(const Size& size)
	{
		m_left = 0;
		m_top = 0;
		m_right = size.width();
		m_bottom = size.height();
	}

	inline Rectangle::Rectangle(const Point& location, const Size& size)
	{
		m_left = location.x();
		m_right = location.x() + size.width();
		m_top = location.y();
		m_bottom = location.y() + size.height();
	}

	inline Rectangle::Rectangle(Word width, Word height)
	{
		m_left = 0;
		m_top = 0;
		m_right = width;
		m_bottom = height;
	}

	inline Rectangle::Rectangle(Word left, Word top, Word width, Word height)
	{
		m_left = left;
		m_top = top;
		m_right = left + width;
		m_bottom = top + height;
	}

	inline void Rectangle::assign(Word left, Word top, Word width, Word height)
	{
		m_left = left;
		m_top = top;
		m_right = left + width;
		m_bottom = top + height;
	}

	inline Word Rectangle::bottom() const
	{
		return m_bottom;
	}

	inline void Rectangle::setBottom(Short bottom)
	{
		m_bottom = bottom;
	}

	inline Word Rectangle::left() const
	{
		return m_left;
	}

	inline void Rectangle::setLeft(Word left)
	{
		m_left = left;
	}

	inline Word Rectangle::right() const
	{
		return m_right;
	}

	inline void Rectangle::setRight(Word right)
	{
		m_right = right;
	}

	inline Word Rectangle::top() const
	{
		return m_top;
	}

	inline void Rectangle::setTop(Word top)
	{
		m_top = top;
	}

	inline Word Rectangle::width() const
	{
		return m_right - m_left;
	}

	inline Word Rectangle::height() const
	{
		return m_bottom - m_top;
	}

	inline Size Rectangle::size() const
	{
		return Size(width(), height());
	}

	inline Point Rectangle::leftTop() const
	{
		return Point(m_left, m_top);
	}

	inline Point Rectangle::location() const
	{
		return Point(m_left, m_top);
	}

	inline Point Rectangle::rightBottom() const
	{
		return Point(m_right, m_bottom);
	}

	inline Bool Rectangle::isValid() const
	{
		return (m_left < m_right) && (m_top < m_bottom);
	}

	inline Bool Rectangle::isInvalid() const
	{
		return (m_left >= m_right) || (m_top >= m_bottom);
	}

	inline Rectangle Rectangle::withSize(const Word w, const Word h) const
	{
		return Rectangle(m_left, m_top, w, h);
	}

	inline Rectangle Rectangle::translated(const Word dx, const Word dy) const
	{
		return Rectangle(m_left + dx, m_top + dy, width(), height());
	}

	inline Rectangle Rectangle::translated(const Point& p) const
	{
		return Rectangle(m_left + p.x(), m_top + p.y(), width(), height());
	}


	inline Rectangle Rectangle::withOrigin(const Word x, const Word y) const
	{
		return Rectangle(m_left - x, m_top - y, width(), height());
	}

	inline 	Rectangle Rectangle::withOrigin(const Point& p) const
	{
		return Rectangle(m_left - p.x(), m_top - p.y(), width(), height());
	}

	inline 	Rectangle Rectangle::leftRectangle(const Word width) const
	{
		return Rectangle(m_left, m_top, width, height());
	}

	inline 	Rectangle Rectangle::rightRectangle(const Word width) const
	{
		return Rectangle(m_right - width, m_top, width, height());
	}

	inline void Rectangle::moveTo(const Word x, const Word y)
	{
		m_right += x - m_left;
		m_bottom += y - m_top;
		m_left = x;
		m_top = y;
	}

	inline void Rectangle::moveTo(const Point& p)
	{
		m_right += p.x() - m_left;
		m_bottom += p.y() - m_top;
		m_left = p.x();
		m_top = p.y();
	}

	inline void Rectangle::setOrigin(Word x, Word y)
	{
		m_left -= x;
		m_right -= x;
		m_top -= y;
		m_bottom -= y;
	}

	inline void Rectangle::setOrigin(const Point& p)
	{
		m_left -= p.x();
		m_right -= p.x();
		m_top -= p.y();
		m_bottom -= p.y();
	}

	inline void Rectangle::setSize(const Word width, const Word height)
	{
		m_right = m_left + width;
		m_bottom = m_top + height;
	}

	inline void Rectangle::setSize(const Size &value)
	{
		m_right = m_left + value.width();
		m_bottom = m_top + value.height();
	}

	inline void Rectangle::translate(Word dx, Word dy)
	{
		m_left += dx;
		m_right += dx;
		m_top += dy;
		m_bottom += dy;
	}

	inline void Rectangle::translate(const Point& p)
	{
		m_left += p.x();
		m_right += p.x();
		m_top += p.y();
		m_bottom += p.y();
	}

	inline void Rectangle::moveLeftBy(Word delta)
	{
		m_left += delta;
	}

	inline void Rectangle::moveTopBy(Word delta)
	{
		m_top += delta;
	}

	inline void Rectangle::moveBottomBy(Word delta)
	{
		m_bottom += delta;
	}

	inline void Rectangle::moveRightBy(Word delta)
	{
		m_right += delta;
	}

	inline void Rectangle::setWidth(Word value)
	{
		m_right = m_left + value;
	}

	inline void Rectangle::setHeight(Word value)
	{
		m_bottom = m_top + value;
	}

	inline void Rectangle::shrinkBy(Word dx, Word dy)
	{
		m_left += dx;
		m_right -= dx;
		m_top += dy;
		m_bottom -= dy;
	}

	inline void Rectangle::shrinkHorizontal(Word delta)
	{
		m_left += delta;
		m_right -= delta;
	}

	inline void Rectangle::shrinkVertical(Word delta)
	{
		m_top += delta;
		m_bottom -= delta;
	}

}

#endif
