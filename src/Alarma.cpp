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

using namespace Tins;

// BSSIDs which we've already seen
std::set<HWAddress<6>> addrs;
// This will be the content of the OUI field in the vendor specific
// tagged option if it's a WPS tag.
const HWAddress<3> expected_oui("00:50:F2");

bool handler(const PDU& pdu) {
    // Only process it once
    const Dot11Data &ip = pdu.rfind_pdu<Dot11Data>(); // Find the IP layer
    std::cout << ip.src_addr() << " -> "
              << ip.dst_addr() << ':' << std::endl;
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
