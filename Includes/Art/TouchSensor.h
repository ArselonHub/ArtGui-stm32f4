/*
 * TouchSens
or.h
 *
 *  Created on: Dec 13, 2016
 *      Author: denizcan
 */

#ifndef ART_TOUCHSENSOR_H_
#define ART_TOUCHSENSOR_H_

#include <Art/Device.h>
#include <Art/CoreEdgeDetector.h>
#include <Art/CoreTimer.h>
#include <Art/Thread.h>
#include <Art/Task.h>
#include <Art/Pin.h>
#include <Art/Point.h>
#include <Art/DataStore.h>

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

		const Point& location() const;
		const Point& rawLocation() const;

		Word restoreCalibration();
		Word loadCalibration();
		Word loadCalibration(DataStore* dataStore);
		Word saveCalibration();
		Word saveCalibration(DataStore* dataStore);

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

		struct CalibrationData
		{
			Float kx1;
			Float kx2;
			Float kx3;
			Float ky1;
			Float ky2;
			Float ky3;
		};

		void resetCalibration();
		void applyRotation();

		Thread*			m_thread;
		EdgeDetector	m_edgeDetector;
		EventTask		m_eventTask;
		EventTimer		m_timer;
		Bool			m_penDown;
		CalibrationData	m_activeCalibration;
		CalibrationData	m_defaultCalibration;

		Point			m_rawLocation;
		Point			m_location;

		friend class Desktop;
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
