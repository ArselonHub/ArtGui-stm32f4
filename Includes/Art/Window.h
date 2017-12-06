#ifndef WINDOW_H
#define WINDOW_H

#include <Art/GroupBox.h>
#include <Art/Loop.h>

namespace Art
{
	class Window : public GroupBox
	{
	public:		
		Window();
		View* focusedView();
		void focusNext();
		void show();
		void hide();
		Word showModal();
		void setModalResult(Word value);

	protected:
		void setFocus(View* view);
		virtual void processGotFocus();
		virtual void processKeyEvent(KeyEvent &e);
	private:
		View*	m_focusedView;
	
		friend class Application;
		friend class View;	
	};

	inline View* Window::focusedView()
	{
		return m_focusedView;
	}

}

#endif
