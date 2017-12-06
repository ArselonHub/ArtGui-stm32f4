#ifndef ART_LABEL_H
#define ART_LABEL_H

#include <Art/View.h>
#include <Art/String.h>

namespace Art
{
	class Label : public View
	{
	public:
		Label();

		virtual void paint(Graphics* g);
		
		const String& text();
		void setText(const String& value);

		Alignment textAlignment();
		void setTextAlignment(Alignment value);
	protected:
		String		m_text;
		Alignment	m_textAlignment;
	};

	inline const Art::String& Label::text()
	{
		return m_text;
	}

	inline Art::Alignment Label::textAlignment()
	{
		return m_textAlignment;
	}

}

#endif
