#ifndef ART_IMAGEVIEW_H
#define ART_IMAGEVIEW_H

#include <Art/View.h>

namespace Art
{
	class ImageView : public View
	{
	public:
		void setImage(Image& value) { image = &value; }
		void setImage(Image* value) { image = value; }
	protected:
		virtual void paint(Graphics* g);
	private:
		Image* image;
		
	};
	
};

#endif
