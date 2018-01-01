#ifndef ART_VIEW_H
#define ART_VIEW_H

#include <Art/BasicQueue.h>
#include <Art/Object.h>
#include <Art/ClipMap.h>
#include <Art/Graphics.h>
#include <Art/KeyEvent.h>
#include <Art/MouseEventArgs.h>
#include <Art/Point.h>
#include <Art/Size.h>

namespace Art
{
	class Container;
	class Window;

	enum ModalResult
	{
		ModalResultNone,
		ModalResultOk,
		ModalResultCancel,
		ModalResultYes,
		ModalResultNo,
	};
	
	class View : public Object
	{
	public:
		View();
		virtual ~View();

		void invalidate();

		const Color backgroundColor() const;
		View* nextSibling() const;
		const Rectangle& bounds() const;
		Rectangle boundingRectangle() const;
		Color color() const;
		Font* font() const;
		Point location() const;
		Word width() const;
		Word height() const;
		Size size() const;
		Container* parent() const;
		Point toScreenLocation(const Point pt);

		Bool isVisible();
		Bool isParentColor();
		Bool isParentBackground();
		Bool isParentFont();
		void setParentColor(Bool value);
		void setParentBackground(Bool value);
		void setParentFont(Bool value);
		
		void setColor(Color value);
		void setFont(const Font* value);
		void setTabStop(bool value);
		void setSize(Size value);	
		void setLocation(Point location);
		void setLocation(Word x, Word y);
		void setBounds(const Rectangle &value);
		void setBounds(Word x, Word y, Word width, Word height);
		void setBackgroundColor(Color value);
		Window* window();
		bool hasFocus() const;
		bool hasInputFocus() const;
		void focus();
		void captureMouse();
		void releaseMouse();
		Bool isMouseCaptured();
		void setVisible(Bool value);

	protected:
		virtual void doMouseDown(MouseEventArgs* args);
		virtual void doMouseMove(MouseEventArgs* args);
		virtual void doMouseUp(MouseEventArgs* args);

		View*		m_invalidNext;
		Point		m_origin;
		Color		m_backgroundColor;
		Rectangle 	m_bounds;

		Color inheritedBGColor();
		void markDirtyClipMap();
		void markDirtyBounds();

		virtual void updateChildren();
		virtual void updateClipMap();
		
		virtual void updateBounds(ClipMap& parentMap, const Point& parentOrigin);
		virtual void paint(Graphics* g);

		virtual void processBoundsChanged();
		virtual void processGotFocus();
		virtual void processLostFocus();
		virtual void previewKeyEvent(KeyEvent& e);
		virtual void processKeyEvent(KeyEvent& e);
	
		virtual void setAttached(bool value);

	private:
		enum DirtyLevel
		{
			DirtyLevelNone,
			DirtyLevelChild,
			DirtyLevelClipMap,
			DirtyLevelBounds			
		};
		
		enum Find
		{
			FindExclude = 0,
			FindInclude = 1,
			FindTabStop = 2,			
		};
		

		View*		m_next;
		Container* 	m_parent;
		Font* 		m_font;
		ClipMap		m_clipMap;
		Color 		m_color;
		DirtyLevel	m_dirtyLevel;

		struct
		{
			Bool 	window:1;
			Bool	attached:1;
			Bool 	visible:1;
			Bool 	enabled:1;
			Bool 	focusable:1;
			Bool 	tabStop:1;
			Bool 	focused:1;
			Bool 	mark:1;
			Bool	parentColor:1;
			Bool	parentBackgroundColor:1;
			Bool	parentFont:1;
		} m_state;

		virtual void doRotationChanged(Rotation newRotation);

		virtual void propagateColor(const Color& color);
		virtual void propagateBackgroundColor(const Color& color);
		virtual void propagateFont(const Font* font);
		virtual void propagateRotation(Rotation newRotation);

		void informLostFocus(View* root);
		void informGotFocus(View* root);
		void dispatchKeyEvent(KeyEvent& e);
		void dispatchPreviewKeyEvent(KeyEvent& e);
		void paintClipMap(Graphics* g);
		
		static Font* s_defaultFont;
		static View* s_invalidList;
		static View* s_focusedView;

		friend class BasicQueue<View>;
		friend class Application;
		friend class Window;
		friend class Container;
		friend class Desktop;
		
	};

	inline View::~View()
	{
	}

	inline const Color View::backgroundColor() const
	{
		return m_backgroundColor;
	}

	inline View* View::nextSibling() const
	{
		return m_next;
	}

	inline Color View::color() const
	{
		return m_color;
	}

	inline Point View::location() const
	{
		return m_bounds.location();
	}

	inline Word View::width() const
	{
		return m_bounds.width();
	}

	inline Word View::height() const
	{
		return m_bounds.height();
	}

	inline Size View::size() const
	{
		return m_bounds.size();
	}

	inline Container* View::parent() const
	{
		return m_parent;
	}

	inline const Rectangle& View::bounds() const
	{
		return m_bounds;
	}

	inline Rectangle View::boundingRectangle() const
	{
		return Rectangle(0, 0, m_bounds.width(), m_bounds.height());
	}

	inline Bool View::isParentColor()
	{
		return m_state.parentColor;
	}

	inline Bool View::isParentBackground()
	{
		return m_state.parentBackgroundColor;
	}

	inline Bool View::isParentFont()
	{
		return m_state.parentFont;
	}

	inline void View::setParentColor(Bool value)
	{
		m_state.parentColor = value;
	}

	inline void View::setParentBackground(Bool value)
	{
		m_state.parentBackgroundColor = value;
	}

	inline void View::setParentFont(Bool value)
	{
		m_state.parentFont = value;
	}

	inline Bool View::isVisible()
	{
		return m_state.attached;
	}

	inline bool View::hasInputFocus() const
	{
		return s_focusedView == this;
	}

	inline void View::setLocation(Word x, Word y)
	{
		setLocation(Point(x, y));
	}

	inline bool View::hasFocus() const
	{
		return (m_state.focused) != 0;
	}

}

#include <Art/Container.h>

#endif
