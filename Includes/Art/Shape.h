/*
 * Shape.h
 *
 *  Created on: Apr 5, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_SHAPE_H_
#define SOURCE_ART_SHAPE_H_

#include <Art/View.h>

namespace Art
{

	class Shape : public View
	{
	public:
		Shape();
		virtual ~Shape();
	protected:
		virtual void paint(Graphics* g);
	};

} /* namespace Art */

#endif /* SOURCE_ART_SHAPE_H_ */
