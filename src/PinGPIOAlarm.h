/*
 * PinGPIOAlarm.h
 *
 *  Created on: 10 jun. 2018
 *      Author: router
 */

#ifndef SRC_PINGPIOALARM_H_
#define SRC_PINGPIOALARM_H_
#include <string>
using namespace std;

class PinGPIOAlarm {
public:
	PinGPIOAlarm();
	PinGPIOAlarm(string x);
	PinGPIOAlarm(string x,bool sim);
	string gpionum;
	int export_gpio();
	virtual ~PinGPIOAlarm();
private:
     // GPIO number associated with the instance of an object
    bool sim;
};

#endif /* SRC_PINGPIOALARM_H_ */
