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

using namespace Tins;
using namespace std;

bool callback(const PDU &pdu) {
    // Find the IP layer
    const IP &ip = pdu.rfind_pdu<IP>();
    // Find the TCP layer
    const TCP &tcp = pdu.rfind_pdu<TCP>();
    cout << ip.src_addr() << ':' << tcp.sport() << " -> "
         << ip.dst_addr() << ':' << tcp.dport() << endl;
    return true;
}

int main(int argc, char* argv[]) {
    Sniffer(argv[1]).sniff_loop(callback);
}
