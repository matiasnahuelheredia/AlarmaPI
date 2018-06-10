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
#include "GPIOClass.h"
using namespace std;
using namespace Tins;


bool handler(const PDU& pdu) {
	    const Dot11ProbeResponse &ip = pdu.rfind_pdu<Dot11ProbeResponse>();
	    std::cout << ip.addr1()<<" "<< ip.addr2() << ip.addr3() <<" "<< std::endl;
	    return true;
}



int main(int argc, char* argv[]) {

	/*GPIOClass* gpio17 = new GPIOClass("17");
	gpio17->export_gpio(); //export GPIO17
	gpio17->setdir_gpio("out"); //GPI17 set to output
	gpio17->setval_gpio("1");*/
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
