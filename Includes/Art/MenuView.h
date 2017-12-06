#ifndef ART_MENUVIEW_H
#define ART_MENUVIEW_H

#include <Art/View.h>
#include <Art/VScrollBar.h>


namespace Art
{
	class MenuView;

	typedef struct
	{
		Graphics * graphics;
		Rectangle rectangle;
		UShort index;
		struct
		{
			Byte isSelected:1;
			Byte isTitle:1;
		};
	} MenuPaintArgs;

	typedef struct MenuViewSettings_
	{
		MenuViewSettings_ * next;
		Short itemCount;
		Short selectedIndex;
		Short topIndex;
		Short visibleItemCount;
		UShort baseIndex;
	} MenuViewSettings;

	typedef void (*MenuViewPaintItemCallback)(MenuView * sender, MenuPaintArgs * args);
	
	class MenuView : public View
	{
	private:
		VScrollBar _scrollBar;
		Short _itemHeight;
	
		union
		{
			struct
			{
				MenuViewSettings * _stack;
				Short _visibleItemCount;
				Short _firstIndex;
				Short _lastIndex;
				Short _topIndex;
				Short _selectedIndex;
			};
			MenuViewSettings _settings;
		};
		Font * _font;
	protected:
		void updateLayout();
		void updateScrollBar();
		virtual void processBoundsChanged();
		void updateSelectedIndex(Short delta);
	public:
		MenuViewPaintItemCallback onPaintItem;

		MenuView();

		virtual bool doKeyDown(KeyMessage * message);
		virtual bool doKeyPress(KeyMessage * message);
		virtual void paint(Graphics * g, Color fillColor);
	
		void paintItem(MenuPaintArgs * args, Char * s0);
		void paintItem(MenuPaintArgs * args, Char * s0, Char * s1);
		void setItemHeight(Short value);
		void setFont(Font * value);
		Short getSelectedIndex();
		void setSelectedIndex(Short value);

		void configure(Short firstIndex, Short lastIndex);
		void configure(Short firstIndex, Short lastIndex, Short selectedIndex);
		void showSubMenu(Short firstIndex, Short lastIndex);
		void showSubMenu(Short firstIndex, Short lastIndex, Short selectedIndex);
		bool goBack();
	};
}

#endif
