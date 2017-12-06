#ifndef ART_VALUEVIEW_H
#define ART_VALUEVIEW_H

#include <Art/View.h>

namespace Art
{
	class ValueView : public View
	{
	public:
		ValueView();
		void setFormat(const Char* value);
		Float getValue() { return displayValue; }
		void setValue(Float value);

	protected:
		virtual void paint(Graphics* g);
		virtual void processKeyEvent(KeyEvent& e);
		
	private:
		Float 	displayValue;
		Char* 	format;
	};
}

#endif
