#ifndef ART_POINT_H
#define ART_POINT_H

#include <Art/Types.h>
#include <Art/Size.h>

namespace Art
{
	class Point
	{
	public:
		Point();
		Point(const Point& p);
		Point(Word x, Word y);
		void assign(Word x, Word y);
		void assign(const Point& p);
		void adjust(Word dx, Word dy);
		void adjustX(Word delta);
		void adjustY(Word delta);
		Word x() const;
		Word y() const;
		void moveXBy(Word delta);
		void moveYBy(Word delta);
		void moveBy(Word dx, Word dy);
		void setX(Word x);
		void setY(Word y);

		void operator -=(const Size& s);
		void operator -=(const Point& p);
		Point operator -(const Point& p) const;
		Point operator -(const Size& s) const;

		void operator +=(const Size& s);
		void operator +=(const Point& p);
		Point operator +(const Point& p) const;

		Bool operator ==(const Point& p) const;

	private:
		Short m_x;
		Short m_y;
	};

	inline Point::Point()
	{
		m_x = 0;
		m_y = 0;
	}

	inline Point::Point(const Point& p)
	{
		m_x = p.m_x;
		m_y = p.m_y;
	}


	inline Point::Point(Word x, Word y)
	{
		m_x = x;
		m_y = y;
	}

	inline void Point::assign(const Point& p)
	{
		m_x = p.m_x;
		m_y = p.m_y;
	}

	inline void Point::assign(Word x, Word y)
	{
		m_x = x;
		m_y = y;
	}

	inline void Point::operator +=(const Point& p)
	{
		m_x += p.m_x;
		m_y += p.m_y;
	}

	inline void Point::operator +=(const Size& s)
	{
		m_x += s.width();
		m_y += s.height();
	}

	inline void Point::adjustX(Word delta)
	{
		m_x += delta;
	}

	inline void Point::adjustY(Word delta)
	{
		m_y += delta;
	}

	inline void Point::moveXBy(Word delta)
	{
		m_x += delta;
	}

	inline void Point::moveYBy(Word delta)
	{
		m_y += delta;
	}

	inline void Point::moveBy(Word dx, Word dy)
	{
		m_x += dx;
		m_y += dy;
	}

	inline void Point::operator -=(const Size& s)
	{
		m_x -= s.width();
		m_y -= s.height();
	}

	inline void Point::operator -=(const Point& p)
	{
		m_x -= p.m_x;
		m_y -= p.m_y;
	}

	inline Point Point::operator -(const Point& p) const
	{
		return Point(m_x - p.m_x, m_y - p.m_y);
	}

	inline Point Point::operator -(const Size& s) const
	{
		return Point(m_x - s.width(), m_y - s.height());
	}

	inline Point Point::operator +(const Point& p) const
	{
		return Point(m_x + p.m_x, m_y + p.m_y);
	}

	inline Word Point::x() const
	{
		return m_x;
	}

	inline void Point::setX(Word x)
	{
		m_x = x;
	}

	inline Word Point::y() const
	{
		return m_y;
	}

	inline void Point::setY(Word y)
	{
		m_y = y;
	}

	inline void Point::adjust(Word dx, Word dy)
	{
		m_x += dx;
		m_y += dy;
	}

	inline Bool Point::operator ==(const Point& p) const
	{
		return (m_x == p.m_x) && (m_y == p.m_y);
	}

}

#endif
