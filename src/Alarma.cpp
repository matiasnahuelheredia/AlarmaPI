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
#include <map>
#include "I2cDisplay.h"
#include <iomanip>
#include <ctime>
#include <pthread.h>
#include <unistd.h>
#define BOARD RASPBERRY_PI
using namespace std;
using namespace Tins;

I2cDisplay disp;
std::map<std::string, string> mapOfWords;
std::map<std::string, string>::iterator it = mapOfWords.begin();
bool handler(const PDU& pdu) {

	    const Dot11ProbeResponse &ip = pdu.rfind_pdu<Dot11ProbeResponse>();
	    auto t = std::time(nullptr);
	    	    auto tm = *std::localtime(&t);

	    	    std::ostringstream oss;
	    	    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
	    	    auto str = oss.str();

	    uint sizeaux=mapOfWords.size();
	    if(mapOfWords[ip.addr1().to_string()].empty())
	    {
	    mapOfWords[ip.addr1().to_string()] = str;
	    mapOfWords[ip.addr2().to_string()] = str;
	    mapOfWords[ip.addr3().to_string()] = str;
	    }




	    if (sizeaux != mapOfWords.size())
	    {
	    	cout<<"INGRESO UNA NUEVA MAC Cantidad:"<<sizeaux<<std::endl;
	    	std::cout << ip.addr1()<<" "<< std::endl;
	    	//<< ip.addr2() << ip.addr3()
	    	if(ip.addr1().to_string().compare("d0:04:01:82:e9:f1")== 0)
	    	{
	    		mapOfWords["d0:04:01:82:e9:f1"]="MATIASNAHUELHEREDIA";
	    	}


	    }
	    return true;
}

void *recorrerMacs(void *data)
{
	/*while(it != mapOfWords.end())
			{
			std::cout<<"Listado de macs \n";
			std::cout<<it->first<<" :: "<<it->second<<std::endl;
			it++;
			}*/
	while(1)
	{
		usleep(100000);
		it=mapOfWords.begin();
		std::cout<<"Listado de macs \n"<<mapOfWords.size();
		while(it != mapOfWords.end())
		{
					std::cout<<it->first<<" :: "<<it->second<<std::endl;
					disp.init();
					disp.lcd_string("INGRESO         ",disp.LCD_LINE_1);
					disp.lcd_string(it->first+"      ",disp.LCD_LINE_2);
					disp.lcd_string(it->second,disp.LCD_LINE_3);
					usleep(1000000);
					it++;
		}
	}
	return NULL;
}

int main(int argc, char* argv[]) {
	disp.init();
	pthread_t hilo;
	pthread_create( &hilo, NULL, recorrerMacs, NULL);
	disp.lcd_string("INICIANDO EL         ",disp.LCD_LINE_1);
	disp.lcd_string("DISPOSITIVO          ",disp.LCD_LINE_2);
	if(argc != 2) {
        std::cout << "Usage: " <<* argv << " <DEVICE>\n";
        return 1;
    }

    SnifferConfiguration config;
    config.set_snap_len(2000);
    config.set_rfmon(true);
    config.set_promisc_mode(true);
    Sniffer sniffer(argv[1], config);
    sniffer.sniff_loop(handler);
	return 0;
}
