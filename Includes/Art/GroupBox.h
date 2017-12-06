#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <Art/Container.h>

namespace Art
{

	enum BorderStyle
	{
		BorderStyleNone,
		BorderStyleGroup,
		BorderStyleToolbox,
		BorderStyleWindow
	};

	class GroupBox : public Container
	{
	public:
		GroupBox();
		Char* title();
		BorderStyle borderStyle();

		void setBorderStyle(const BorderStyle value);
		void setTitle(const Char* value);

	protected:
		BorderStyle m_borderStyle;
		Char* m_title;
		
		virtual void paint(Graphics* g);

	};

	inline Char* GroupBox::title()
	{
		return m_title;
	}

	inline BorderStyle GroupBox::borderStyle()
	{
		return m_borderStyle;
	}
}

#endif
