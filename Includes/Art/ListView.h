#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <Art/Container.h>
#include <Art/VScrollBar.h>

namespace Art
{
	class ListView : public Container
	{
	public:
		typedef struct
		{
			Graphics*	graphics;
			ListView*	sender;
			Rectangle	rectangle;
			Short 		index;
			Bool		selected;
			
			ShortL getIndex() { return index; }
			ShortL getWidth() { return rectangle.width(); }
		} DrawItemArgs;

		Signal<DrawItemArgs&> onDrawItem() SIGNAL;
		
		ListView();
		const Font* getFont() { return font; }

		void selectItem(const Word index);
		void setCount(const Word value);
		void setFont(const Font* value);
		void setFont(const Font& value) { setFont(&value); }
		ShortL getSelectedIndex() { return selectedIndex; }

		void drawDefault(DrawItemArgs& args, const Char* s, const Word alignment = AlignLeft | AlignVCenter);
		void drawLeft(DrawItemArgs& args, const Word width);
		void drawLeft(DrawItemArgs& args, const Word width, const Char* s, const Word alignment = AlignLeft | AlignVCenter);
		void drawRight(DrawItemArgs& args, const Word width);
		void drawRight(DrawItemArgs& args, const Word width, const Char* s, const Word alignment = AlignRight | AlignVCenter);

	protected:
		VScrollBar 	scrollBar;
		const Font*		font;
		Short		count;
		Short		selectedIndex;
		Short		topIndex;
		Short		itemSize;
		Short		visibleCount;

		virtual void paint(Graphics* g);
		virtual void processBoundsChanged();
		virtual void processKeyEvent(KeyEvent& e);

	private:
		void processKey(KeyEvent& args);
		void updateIndexes();
		void updateLayout();
		

	};
}

#endif
