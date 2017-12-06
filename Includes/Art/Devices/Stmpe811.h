/*
 * STMPE811.h
 *
 *  Created on: Dec 13, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_DEVICES_STMPE811_H_
#define SOURCE_ART_DEVICES_STMPE811_H_

#include <Art/TouchSensor.h>

namespace Art
{
	class Stmpe811 : public TouchSensor
	{
	public:
		enum Register
		{
			RegisterChipId		= 0x00,
			RegisterVersion		= 0x01,
			RegisterSysCtrl2	= 0x04,
			RegisterIntCtrl		= 0x09,
			RegisterIntEn		= 0x0A,
			RegisterIntSta		= 0x0B,
			RegisterTscCtrl		= 0x40,
			RegisterTscCfg		= 0x41,
			RegisterFifoTh		= 0x4A,
			RegisterFifoSta		= 0x4B,
			RegisterFifoSize	= 0x4C,
			RegisterTscDataXyz	= 0x52,
			RegisterFractionZ	= 0x56

		};

		enum Average
		{
			Average1Sample,
			Average2Samples,
			Average4Samples,
			Average8Samples
		};

		enum TouchDelay
		{
			TouchDelay10us,
			TouchDelay50us,
			TouchDelay100us,
			TouchDelay500us,
			TouchDelay1ms,
			TouchDelay5ms,
			TouchDelay10ms,
			TouchDelay50ms
		};

		enum Settling
		{
			Settling10us,
			Settling100us,
			Settling500us,
			Settling1ms,
			Settling5ms,
			Settling10ms,
			Settling50ms,
			Settling100ms
		};

		Stmpe811();

		Average average() const;
		Settling settling() const;
		TouchDelay touchDelay() const;
		void setAverage(Average average);
		void setSettling(Settling settling);
		void setTouchDelay(TouchDelay touchDelay);
		Word status();

		Word writeUByte(Register address, Word value);

		virtual Word writeData(Register address, void* buffer, Word length) = 0;
		virtual Word readData(Register address, void* buffer, Word length) = 0;
	protected:
		virtual void doEventOccured();
		virtual Word openDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();
		void clearInterrupt();
	private:
		Word updateTouchSettings();

		Average		m_average;
		TouchDelay	m_touchDelay;
		Settling	m_settling;
	};

	inline Stmpe811::Average Stmpe811::average() const
	{
		return m_average;
	}

	inline Stmpe811::Settling Stmpe811::settling() const
	{
		return m_settling;
	}

	inline Stmpe811::TouchDelay Stmpe811::touchDelay() const
	{
		return m_touchDelay;
	}

} /* namespace Art */

#endif /* SOURCE_ART_DEVICES_STMPE811_H_ */
