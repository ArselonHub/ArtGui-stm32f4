#ifndef ART_MENUWINDOW_H
#define ART_MENUWINDOW_H

#include <Art/String.h>
#include <Art/Label.h>
#include <Art/ListView.h>
#include <Art/Window.h>

namespace Art
{
	
	class SubMenu
	{
	public:
		Signal<ListView::DrawItemArgs&> onDrawItem() SIGNAL;
		Signal<KeyEvent&> onKeyEvent() SIGNAL;
		String title;
		Word count;
	private:
		SubMenu* parent;
		Word selectedIndex;
		friend class MenuWindow;
	};
		
	enum Prompt
	{
		PromptNoYes,
		PromptYesNo,
		PromptYesNoCancel		
	};
	
	class PromptSubMenu : public SubMenu
	{
	public:
		PromptDelegate onRespond;		
	};
	
	class MenuWindow : public Window
	{
	public:
		MenuWindow();
		void showMenu(SubMenu* value);
		void stepBack();
				
		ListView	listView;
		Label		label;
		Signal<KeyEvent&> onKeyEvent();
	
		void prompt(String title, Prompt value, PromptDelegate callback); 
	protected:
		virtual void previewKeyEvent(KeyEvent& e);
		
	private:
		void handleDrawItem(ListView::DrawItemArgs& args);
		void prepareMenu();
		void drawYesNoPrompt(ListView::DrawItemArgs& args);
		void handlePromptKeyEvent(KeyEvent& event);
	
		SubMenu* current;
	
	};
}

#endif

