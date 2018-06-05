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
using namespace Tins;


bool handler(const PDU& pdu) {
    // Only process it once
	auto t = std::time(nullptr);
	    auto tm = *std::localtime(&t);

    const Dot11Data &ip = pdu.rfind_pdu<Dot11Data>(); // Find the IP layer
    std::cout<< std::put_time(&tm, "%d-%m-%Y %H:%M:%S")<<' '  << ip.src_addr() << " "
              << ip.dst_addr() << std::endl;
    return true;
}



int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "Usage: " <<* argv << " <DEVICE>\n";
        return 1;
    }
    // Only sniff beacons
    SnifferConfiguration config;
    config.set_snap_len(2000);
    config.set_rfmon(true);
    config.set_promisc_mode(true);
    //config.set_filter("wlan type mgt subtype beacon");
    Sniffer sniffer(argv[1], config);
    sniffer.sniff_loop(handler);
}
