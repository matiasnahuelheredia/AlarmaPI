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
#include <tins/tins.h>
#include <string>

#include <tins/tins.h>
#include <iostream>
#include <set>
#include <string>


using namespace Tins;

// BSSIDs which we've already seen
std::set<HWAddress<6>> addrs;
// This will be the content of the OUI field in the vendor specific
// tagged option if it's a WPS tag.
const HWAddress<3> expected_oui("00:50:F2");

bool handler(const PDU& pdu) {
    const Dot11Beacon& beacon = pdu.rfind_pdu<Dot11Beacon>();
    // Only process it once
    if(addrs.insert(beacon.addr3()).second) {
        // Iterate the tagged options
        for(const auto& opt : beacon.options()) {
            // Is this a vendor-specific tag?
            if(opt.option() == Dot11::VENDOR_SPECIFIC) {
                // Make sure there's enough size for the OUI + identifier
                if(opt.data_size() >= 4) {
                    // Retrieve the OUI field
                    HWAddress<3> addr = opt.data_ptr();
                    // Are we interested in this OUI and is it a WPS tag?
                    if(addr == expected_oui && opt.data_ptr()[3] == 0x04) {
                        std::cout << "[+] Access point: " << beacon.ssid() << " uses WPS\n";
                    }
                }
            }
        }
    }
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
    config.set_promisc_mode(true);
    config.set_filter("wlan type mgt subtype beacon");
    Sniffer sniffer(argv[1], config);
    sniffer.sniff_loop(handler);
}
