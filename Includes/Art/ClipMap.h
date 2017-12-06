#ifndef ART_CLIPMAP_H
#define ART_CLIPMAP_H

#include <Art/BasicStack.h>
#include <Art/Rectangle.h>

namespace Art
{
	class ClipRectangle : public Rectangle
	{
	public:
		ClipRectangle(const Rectangle& r);
		ClipRectangle(Word left, Word top, Word right, Word bottom);
	private:
		ClipRectangle*	m_next;
		friend BasicStack<ClipRectangle>;
	};

	class ClipMap
	{
	public:		
		//static void printEmptyCount();

		void clear();			
		void copy(ClipMap& source);
		void copyIntersection(ClipMap& source, const Rectangle& r);
		void clean();
		void setOrigin(const Point& value);
			
		void add(const Rectangle& r);
		void substract(const Rectangle& r);
		void translate(const Point& pt);
		void intersect(const Rectangle& r);
		void intersect(const ClipMap& other);	

	private:
		typedef BasicStack<ClipRectangle> List;
		List list;

		friend class Application;
		friend class View;
		friend class Container;
	};

	inline ClipRectangle::ClipRectangle(const Rectangle& r)
		: Rectangle(r)
	{
	}

	inline ClipRectangle::ClipRectangle(Word left, Word top, Word right,
			Word bottom)
		: Rectangle(left, top, right - left, bottom - top)
	{
	}

}

#endif
