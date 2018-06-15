/*
 * I2cDisplay.cpp
 *
 *  Created on: 12 jun. 2018
 *      Author: router
 */

#include "I2cDisplay.h"
#include <iostream>
#define BOARD RASPBERRY_PI
using namespace std;
I2cDisplay::I2cDisplay() {
	// TODO Auto-generated constructor stub

}
int I2cDisplay::lcd_byte(int bits,bool data)
{
	int bits_high = data | (bits & 0xF0) | this->LCD_BACKLIGHT;
	int bits_low = data | ((bits<<4) & 0xF0) | LCD_BACKLIGHT;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	lcd.write(bits_high);
	this->lcd_toggle_enable(bits_high);
	lcd.write(bits_low);
	this->lcd_toggle_enable(bits_low);
return	bits_high;
}

void I2cDisplay::lcd_toggle_enable(int bits)
{
// Toggle enable
  std::this_thread::sleep_for(std::chrono::milliseconds(this->E_DELAY*1000));
  lcd.write((bits | ENABLE));
  std::this_thread::sleep_for(std::chrono::milliseconds(this->E_DELAY*1000));
  lcd.write((bits & ~ENABLE));
  std::this_thread::sleep_for(std::chrono::milliseconds(this->E_DELAY*1000));
}

void I2cDisplay::init()
{
	this->lcd.open("/dev/i2c-1",this->I2C_ADDR);
	lcd_byte(0x33,LCD_CMD); // 110011 Initialise
	lcd_byte(0x32,LCD_CMD); // 110010 Initialise
	lcd_byte(0x06,LCD_CMD); // 000110 Cursor move direction
	lcd_byte(0x0C,LCD_CMD); // 001100 Display On,Cursor Off, Blink Off
	lcd_byte(0x28,LCD_CMD); // 101000 Data length, number of lines, font size
	lcd_byte(0x01,LCD_CMD); // 000001 Clear display
	std::this_thread::sleep_for(std::chrono::milliseconds(this->E_DELAY*1000));
	cout<< "iniciando";
}

I2cDisplay::~I2cDisplay() {
	// TODO Auto-generated destructor stub
}

