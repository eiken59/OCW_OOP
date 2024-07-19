#include <iostream>
#include "AirTicket.h"
using namespace std;

int main(int argc, char ** argv) {
    AirTicket tkt1;
    tkt1.setName("Peter Woods");
    tkt1.setMiles(25000);
    cout << tkt1.getName() << " pays " << tkt1.calculatePrice() << endl;

    AirTicket *tkt2 = new AirTicket;
    tkt2->setName("Laura Clinton");
    tkt2->setMiles(3000);
    cout << tkt2->getName() << " pays " << tkt2->calculatePrice() << endl;
    delete tkt2;

    return 0;
}