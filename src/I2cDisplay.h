/*
 * I2cDisplay.h
 *
 *  Created on: 12 jun. 2018
 *      Author: router
 */

#ifndef SRC_I2CDISPLAY_H_
#define SRC_I2CDISPLAY_H_
#include <cppgpio.hpp>
class I2cDisplay {
public:
	I2cDisplay();
	void init();
	int LCD_LINE_1 = 0x80; // LCD RAM address for the 1st line
	int LCD_LINE_2 = 0xC0; // LCD RAM address for the 2nd line
	int LCD_LINE_3 = 0x94; // LCD RAM address for the 3rd line
	int LCD_LINE_4 = 0xD4; // LCD RAM address for the 4th line
	void lcd_string(char* message,int line);
	virtual ~I2cDisplay();
private:
	GPIO::I2C lcd;
	int lcd_byte(int bits,bool data);
	void lcd_toggle_enable(int bits);
	int	I2C_ADDR  = 0x27; // I2C device address
	int LCD_WIDTH = 24;   // Maximum characters per line
	int LCD_CHR = 1; // Mode - Sending data
	int LCD_CMD = 0; // Mode - Sending command
	int LCD_BACKLIGHT  = 0x08;  // On
	int ENABLE = 0b00000100; // Enable bit
	int E_PULSE = 0.0005;
	int E_DELAY = 0.0005;
};

#endif /* SRC_I2CDISPLAY_H_ */
