#ifndef ART_CONTAINER_H
#define ART_CONTAINER_H

#include <Art/BasicQueue.h>
#include <Art/View.h>

namespace Art
{
	class Container : public View
	{
	public:
		Container();
		void add(View* view);
		void remove(View* view);

	protected:
		View* viewFromPoint(const Point& pt);

		virtual void doMouseDown(MouseEventArgs* args);
		virtual void doMouseMove(MouseEventArgs* args);
		virtual void doMouseUp(MouseEventArgs* args);

		BasicQueue<View> m_children;
		ClipMap m_visibleMap;

		virtual void updateChildren();
		virtual void updateClipMap();
		virtual void updateBounds(ClipMap& parentMap, const Point& parentOrigin);

		virtual void setAttached(bool value);

	private:
		virtual void propagateColor(const Color& color);
		virtual void propagateBackgroundColor(const Color& color);
		virtual void propagateFont(const Font* font);

		friend View;
	};
}

#endif
