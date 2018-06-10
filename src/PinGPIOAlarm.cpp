/*
 * PinGPIOAlarm.cpp
 *
 *  Created on: 10 jun. 2018
 *      Author: router
 */

#include "PinGPIOAlarm.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
PinGPIOAlarm::PinGPIOAlarm() {
	// TODO Auto-generated constructor stub
	this->gpionum=7;
	this->sim=true;
}
PinGPIOAlarm::PinGPIOAlarm(string gnum) {
this->gpionum=gnum;
this->sim=true;
}
PinGPIOAlarm::PinGPIOAlarm(string gnum,bool simulate) {
this->gpionum=gnum;
this->sim=simulate;
}

//Destructor
PinGPIOAlarm::~PinGPIOAlarm() {
}


int PinGPIOAlarm::export_gpio()
{

    string export_str = "/sys/class/gpio/export";
    if(this->sim)
    {
    	export_str = "/tmp/gpio.tmp";
    }
    else
    {
    	export_str = "/sys/class/gpio/export";
    }
    cout << "exportando " << this->gpionum << "al archivo " << export_str;
    ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    /*if (exportgpio < 0){
        cout << " OPERATION FAILED: Unable to export GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
    }*/
    exportgpio << this->gpionum ; //write GPIO number to export
    exportgpio.close(); //close export file
    return 0;
}


