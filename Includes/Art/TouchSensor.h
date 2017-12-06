/*
 * TouchSens
or.h
 *
 *  Created on: Dec 13, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_TOUCHSENSOR_H_
#define SOURCE_ART_TOUCHSENSOR_H_

#include <Art/CoreEdgeDetector.h>
#include <Art/Thread.h>
#include <Art/Task.h>
#include <Art/Pin.h>
#include <Art/CoreTimer.h>
#include <Art/Point.h>
#include <Art/DataStore.h>
#include <Art/Device.h>

namespace Art
{
	class TouchSensor : public Device
	{
	public:
		TouchSensor();
		Pin* eventPin() const;
		Word setEventPin(Pin* pin);
		const Thread* thread() const;
		void setThread(Thread* thread);
		void calibrate();
		void calibrate(const Point* references, const Point* samples);
		void test();
		Word openWith(DataStore* dataStore);

		const Point& location() const;
		const Point& rawLocation() const;

		virtual Word loadSettings(DataStore* dataStore);
		virtual Word saveSettings(DataStore* dataStore);

	protected:
		virtual void doEventOccured() = 0;
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();
		void processTouchData(Word x, Word y, Word z);
		void processTouchState(Bool value);
	private:

		class EdgeDetector : public CoreEdgeDetector
		{
			virtual void doEventSvc();
		};

		class EventTimer : public CoreTimer
		{
			virtual void doTimeoutSvc();
		};

		class EventTask : public Task
		{
			virtual void execute();
		};

		Thread*			m_thread;
		EdgeDetector	m_edgeDetector;
		EventTask		m_eventTask;
		EventTimer		m_timer;
		Bool			m_penDown;
		Float			m_kx1;
		Float			m_kx2;
		Float			m_kx3;
		Float			m_ky1;
		Float			m_ky2;
		Float			m_ky3;
		Point			m_rawLocation;
		Point			m_location;
	};

	inline const Thread* TouchSensor::thread() const
	{
		return m_thread;
	}

	inline Pin* TouchSensor::eventPin() const
	{
		return m_edgeDetector.pin();
	}

	inline Word TouchSensor::setEventPin(Pin* pin)
	{
		return m_edgeDetector.setPin(pin);
	}

	inline void TouchSensor::setThread(Thread* thread)
	{
		m_thread = thread;
	}

	inline const Point& TouchSensor::location() const
	{
		return m_location;
	}

	inline const Point& TouchSensor::rawLocation() const
	{
		return m_rawLocation;
	}
} /* namespace Art */

#endif /* SOURCE_ART_TOUCHSENSOR_H_ */
