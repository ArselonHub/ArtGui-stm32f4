#ifndef ART_APPLICATION_H
#define ART_APPLICATION_H

#include <Art/Timer.h>
#include <Art/ClipMap.h>
#include <Art/Desktop.h>
#include <Art/Window.h>
#include <Art/Loop.h>
#include <Art/TouchSensor.h>
#include <Art/MouseEventArgs.h>

#define AT_UPDATE		((View*)1)
#define AT_DELEGATE		((View*)2)

namespace Art
{
	class Application
	{
	public:
		Application();
		void performKeyDown(Key key);
		void performKeyUp(Key key);

		Word run();
		void setDefaultFont(const Font* value);
		View* focusedView();

	private:
		Point clipLocation(const Point& location);

		void keyPressTimerTimeout();

		void processKeyDown(Key key);
		void processKeyPress();
		void processKeyUp(Key key);
		void processTouchDown(MouseButton button, const Point& location);
		void processTouchMove(MouseButton button, const Point& location);
		void processTouchUp(MouseButton button, const Point& location);

		Timer	m_keyPressTimer;
		Key		m_lastKey;
		Loop*			m_loop;
		View*			m_mouseCapturer;
		Point			m_mouseLocation;
		MouseButton		m_mouseButtons;

		friend class View;
		friend class Window;
		friend class TouchSensor;
	};

	extern Application* application();

	inline void Application::setDefaultFont(const Font* value)
	{
		View::s_defaultFont = (Font*)value;
	}

	inline View* Application::focusedView()
	{
		return View::s_focusedView;
	}

}

#endif
