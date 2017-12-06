/*
 * RleImage.h
 *
 *  Created on: Jan 30, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_RLEIMAGE_H_
#define SOURCE_ART_PRIVATE_RLEIMAGE_H_

#include <Art/Image.h>

namespace Art
{
	namespace Private
	{
		class RleImage : public Image
		{
		public:
			RleImage(const void* data);

			const void* data() const;
			const void* palette() const;

		private:
			virtual void pushOn(GraphicsWriter* writer, const Rectangle& box,
					const Color& background) const;

			const void*	m_data;
			const void*	m_palette;
		};

		inline const void* RleImage::data() const
		{
			return m_data;
		}

		inline const void* RleImage::palette() const
		{
			return m_palette;
		}

	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_RLEIMAGE_H_ */
