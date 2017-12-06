/*
 * CalibrationWindow.h
 *
 *  Created on: Dec 26, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_LOCAL_CALIBRATIONWINDOW_H_
#define SOURCE_ART_LOCAL_CALIBRATIONWINDOW_H_

#include <Art/Window.h>
#include <Art/Timer.h>
#include <Art/TouchSensor.h>

namespace Art
{

	class CalibrationWindow : public Window
	{
	public:
		CalibrationWindow();
		virtual ~CalibrationWindow();
		Word execute(TouchSensor* touchSensor);
		Word test();
		const Point* samplePoints() const;
		const Point* referencePoints() const;
	protected:
		virtual void doMouseDown(MouseEventArgs* args);
		virtual void doMouseMove(MouseEventArgs* args);
		virtual void paint(Graphics* g);
	private:
		void animate(void* sender);

		enum State
		{
			StateSampleCenter,
			StateSampleTopLeft,
			StateSampleTopRight,
			StateSampleBottomRight,
			StateSampleBottomLeft,
			StateSampleReturn,
			StateTest
		};

		Word 		m_state;
		Point		m_crossLocation;
		Point		m_lastLocation;
		Point		m_samplePoints[5];
		Point		m_referencePoints[5];
		Word		m_animationStep;
		Timer		m_timer;
		TouchSensor*	m_touchSensor;
	};

	inline const Point* CalibrationWindow::samplePoints() const
	{
		return m_samplePoints;
	}

	inline const Point* CalibrationWindow::referencePoints() const
	{
		return m_referencePoints;
	}

} /* namespace Art */

#endif /* SOURCE_ART_LOCAL_CALIBRATIONWINDOW_H_ */
