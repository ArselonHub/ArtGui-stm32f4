/*
 * LcdInterface.h
 *
 *  Created on: Oct 15, 2016
 *      Author: denizcan
 */

#ifndef ART_LCDINTERFACE_H_
#define ART_LCDINTERFACE_H_

#include <Art/Types.h>

namespace Art
{

	class LcdInterface
	{
	public:
		virtual void writeIndex(Word index) = 0;
		virtual void writeRegister(Word index, UWord value);
		virtual void writeSingle(UWord value) = 0;
		virtual void writeMultiple(UWord value, Word count) = 0;
		virtual void writeBuffer(UWord value) = 0;
	};

} /* namespace Art */

#endif /* SOURCE_ART_LCDINTERFACE_H_ */
