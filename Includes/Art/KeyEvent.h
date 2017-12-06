#ifndef ART_KEYEVENT_H
#define ART_KEYEVENT_H

#include <Art/Types.h>

namespace Art
{
	class View;

	enum Key
	{
		KeyLeft = 128,
		KeyRight	= 129,
		KeyDown		= 130,
		KeyUp		= 131,
		KeyPageDown	= 132,
		KeyPageUp	= 133,
		KeyHome		= 134,
		KeyEnd		= 135,

		KeyF1 		= 141,
		KeyF2 		= 142,
		KeyF3	 	= 143,
		KeyF4 		= 144,
		KeyF5 		= 145,
		KeyF6 		= 146,
		KeyF7 		= 147,
		KeyF8 		= 148,
		KeyF9 		= 149,
		KeyF10		= 150,
		KeyF11		= 151,
		KeyF12		= 152,

		KeyBackspace = 8,
		KeyTab 		= 9,
		KeyPlus 	= '+',
		KeyMinus 	= '-',
		KeyEnter 	= 13,
		KeyEscape	= 27,
		KeyStar 	= '*',
		KeyPound 	= '#',

		Key0 		= '0',
		Key1		= '1',
		Key2		= '2',
		Key3		= '3',
		Key4		= '4',
		Key5		= '5',
		Key6		= '6',
		Key7		= '7',

		KeyA		= 'A',
		KeyB		= 'B',
		KeyX		= 'X',
		KeyY		= 'Y',
		KeyZ		= 'Z',
	};	

	enum KeyModifiers
	{
		KeyModifierShift = 0x01,
		KeyModifierControl = 0x02,
		KeyModifierSuper = 0x04,
		KeyModifierAlternate = 0x08,
		KeyModifierFirst = 0x10,
		KeyModifierPressed = 0x20,
		KeyModifierHandled = 0x40,
		KeyModifierReleased = 0x00
	};
	ENUMFLAGS(KeyModifiers);
	
	class KeyEvent
	{
	public:			
		KeyEvent(View* target, Key key, KeyModifiers modifiers)
		{
			this->target = target;
			this->key = key;
			this->modifiers = modifiers;
		}
		
		Key getKey() const { return key; }
		KeyModifiers getModifiers() const { return modifiers; }
		View* getTarget() const { return target; }
		Bool isHandled() const { return (modifiers & KeyModifierHandled) != 0; }
		Bool isPressed() const { return (modifiers & KeyModifierPressed) != 0; }
		Bool isReleased() const { return (modifiers & KeyModifierPressed) == 0; }
		void markAsHandled() { modifiers |= KeyModifierHandled; }
		
	private:
		View*			target;
		Key				key;
		KeyModifiers	modifiers;
	};

}

#endif
