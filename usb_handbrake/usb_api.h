#ifndef USBserial_h_
#define USBserial_h_

#include <inttypes.h>

#include "keylayouts.h"
#include "Print.h"
#include "Stream.h"

extern uint8_t handbrake_report_data[1];

class usb_handbrake_class
{
private:
	bool     autoSendState;

	uint8_t  throttle;


public:
	usb_handbrake_class();

	void begin(bool initAutoSendState = true);
	void end();
	void setThrottle(uint8_t value);

	void sendState();
};

extern usb_handbrake_class Handbrake;

class usb_serial_class : public Stream
{
	public:
	// standard Arduino functions
	void begin(long);
	void end();
	virtual int available();
	virtual int read();
	virtual int peek();
	virtual void flush();
	virtual size_t write(uint8_t);
	using Print::write;
	operator bool();
	// Teensy extensions
	void send_now(void);
	uint32_t baud(void);
	uint8_t stopbits(void);
	uint8_t paritytype(void);
	uint8_t numbits(void);
	uint8_t dtr(void);
	uint8_t rts(void);
	private:
	uint8_t readnext(void);
};

extern usb_serial_class Serial;


#endif
