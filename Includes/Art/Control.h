/*
 * Control.h
 *
 *  Created on: Jan 6, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_CONTROL_H_
#define SOURCE_ART_CONTROL_H_

#include <Art/View.h>
#include <Art/String.h>
#include <Art/Color.h>

namespace Art
{

	class Control : public View
	{
	public:
		Control();
		virtual ~Control();

		const String& text() const;
		void setText(const String& text);

	protected:

	private:
		String	m_text;
	};

	inline const String& Control::text() const
	{
		return m_text;
	}

} /* namespace Art */

#endif /* SOURCE_ART_CONTROL_H_ */
