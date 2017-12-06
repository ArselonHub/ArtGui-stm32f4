#ifndef VSCROLLBAR_H
#define VSCROLLBAR_H

#include <Art/View.h>

namespace Art
{
	class VScrollBar : public View
	{
	public:
		VScrollBar();
		
		ShortL getMaximum() { return maximum; }
		ShortL getMinimum() { return minimum; }
		ShortL getValue() { return value; }

		void setMaximum(ShortL value);
		void setMinimum(ShortL value);
		void setValue(ShortL value);

	protected:
		virtual void paint(Graphics* g);

	private:
		Short maximum;
		Short minimum;
		Short value;

	};
}

#endif
