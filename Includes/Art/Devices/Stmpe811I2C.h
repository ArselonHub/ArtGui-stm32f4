/*
 * STMPE811.h
 *
 *  Created on: Dec 13, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_DEVICES_STMPE811I2C_H_
#define SOURCE_ART_DEVICES_STMPE811I2C_H_

#include <Art/Devices/Stmpe811.h>
#include <Art/I2CDevice.h>

namespace Art
{
	class Stmpe811I2C : public Stmpe811
	{
	public:
		Stmpe811I2C();
		I2CPort* i2cPort() const;
		void setI2CPort(I2CPort* port);


		// STMPE811
		virtual Word writeData(Register index, void* buffer, Word length);
		virtual Word readData(Register index, void* buffer, Word length);
	protected:
		virtual Word openDevice();
		virtual Word closeDevice();
	private:
		I2CDevice	m_i2cDevice;

	};

	inline I2CPort* Stmpe811I2C::i2cPort() const
	{
		return m_i2cDevice.port();
	}

	inline void Stmpe811I2C::setI2CPort(I2CPort* port)
	{
		m_i2cDevice.setPort(port);
	}
} /* namespace Art */

#endif /* SOURCE_ART_DEVICES_STMPE811I2C_H_ */
