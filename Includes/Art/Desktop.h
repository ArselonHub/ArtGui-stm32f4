#ifndef ART_DESKTOP_H
#define ART_DESKTOP_H

#include <Art/Display.h>
#include <Art/TouchSensor.h>
#include <Art/View.h>
#include <Art/Window.h>
#include <Art/Timer.h>

namespace Art
{
	class Application;
	class Desktop;

	Desktop* desktop();

	class Desktop : private Container
	{
	public:
		Desktop();
		virtual ~Desktop();

		Display* display() const;

	private:
		void update();
		void updateObject(void* sender);
		void triggerUpdate();
		void setDisplay(Display* value);
		Word switchRotation(Rotation newValue);

		Display*		m_display;
		TouchSensor*	m_touchSensor;
		Timer			m_updateTimer;

		static Desktop s_desktop;

		friend class View;
		friend class Window;
		friend class Application;
		friend class Display;
		friend class TouchSensor;

		friend Desktop* desktop();
	};

	inline Display* Desktop::display() const
	{
		return m_display;
	}

	inline Desktop* desktop()
	{
		return &Desktop::s_desktop;
	}

}

#endif
