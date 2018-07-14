#ifndef usb_serial_h__
#define usb_serial_h__

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/**************************************************************************
 *
 *  Configurable Options
 *
 **************************************************************************/

#define VENDOR_ID               0x16C0
#define PRODUCT_ID              0x0489
#define MANUFACTURER_NAME	{'E','n','t','r','i','p','p','y'}
#define MANUFACTURER_NAME_LEN	8
#define PRODUCT_NAME		{'H','y','d','r','a','u','l','i','c',' ','H','a','n','d','b','r','a','k','e'}
#define PRODUCT_NAME_LEN	19
#define TRANSMIT_FLUSH_TIMEOUT  4   /* in milliseconds */
#define TRANSMIT_TIMEOUT        25   /* in milliseconds */


/**************************************************************************
 *
 *  Endpoint Buffer Configuration
 *
 **************************************************************************/

// 0: control				64
// 1: debug IN				64x2
// 2: debug OUT				32x2
// 3: keyboard IN			8x2
// 4: mouse IN			 	16x2
// 5: joystick IN			16x2
// 6: keyboard media IN			8x2

// Some operating systems, especially Windows, may cache USB device
// info.  Changes to the device name may not update on the same
// computer unless the vendor or product ID numbers change, or the
// "bcdDevice" revision code is increased.

#define STR_PRODUCT             L"Hydraulic Handbrake"
#define ENDPOINT0_SIZE          64

#define DEBUG_INTERFACE		1
#define DEBUG_TX_ENDPOINT	1
#define DEBUG_TX_SIZE		64
#define DEBUG_TX_BUFFER		EP_DOUBLE_BUFFER
#define DEBUG_TX_INTERVAL	1
#define DEBUG_RX_ENDPOINT	2
#define DEBUG_RX_SIZE		32
#define DEBUG_RX_BUFFER		EP_DOUBLE_BUFFER
#define DEBUG_RX_INTERVAL	2

#define HANDBRAKE_INTERFACE	0
#define HANDBRAKE_ENDPOINT	3
#define HANDBRAKE_SIZE		1
#define HANDBRAKE_BUFFER	EP_DOUBLE_BUFFER
#define HANDBRAKE_INTERVAL	2

#define NUM_ENDPOINTS		4
#define NUM_INTERFACE		2


// setup
void usb_init(void);			// initialize everything
void usb_shutdown(void);		// shut off USB

// variables
extern volatile uint8_t usb_configuration;
extern volatile uint8_t usb_suspended;
extern volatile uint8_t debug_flush_timer;

extern uint8_t handbrake_report_data[1];




#ifdef __cplusplus
} // extern "C"
#endif

#endif
