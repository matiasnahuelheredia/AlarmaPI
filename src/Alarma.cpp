//============================================================================
// Name        : Alarma.cpp
// Author      : Matias Nahuel Heredia
// Version     :
// Copyright   : GPL V2
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <tins/tins.h>
#include <iostream>
#include <string>
#include <tins/tins.h>
#include <set>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>
#include <cppgpio.hpp>
#include "I2cDisplay.h"
#define BOARD RASPBERRY_PI
using namespace std;
using namespace Tins;
GPIO::I2C lcd;
int LCD_BACKLIGHT  = 0x08;
bool handler(const PDU& pdu) {
	    const Dot11ProbeResponse &ip = pdu.rfind_pdu<Dot11ProbeResponse>();
	    std::cout << ip.addr1()<<" "<< ip.addr2() << ip.addr3() <<" "<< std::endl;
	    return true;
}
int lcd_byte(int bits,bool data)
{
	int bits_high = data | (bits & 0xF0) | LCD_BACKLIGHT;
	//int bits_low = data | ((bits<<4) & 0xF0) | LCD_BACKLIGHT
// High bits

return	bits_high;
}


int main(int argc, char* argv[]) {

	I2cDisplay disp;
	disp.init();

	/*while(true)
	{
	GPIO::DigitalOut out(4);
	out.on();
	cout<< "apagando\n";
	out.off();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}*/
	/*lcd(4, 20, "/dev/i2c-1", 0x27)
	lcd.fill();
	        lcd.write(0, 0, "Please dial me!");
	        lcd.write(1, 0, "Will exit at #42");*/
    /*
	if(argc != 2) {
        std::cout << "Usage: " <<* argv << " <DEVICE>\n";
        return 1;
    }

    SnifferConfiguration config;
    config.set_snap_len(2000);
    config.set_rfmon(true);
    config.set_promisc_mode(true);
    Sniffer sniffer(argv[1], config);
    sniffer.sniff_loop(handler);*/
	return 0;
}
