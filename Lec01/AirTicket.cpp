#include <iostream>
#include "AirTicket.h"
using namespace std;

AirTicket::AirTicket() {
    name = "unknown";
    miles = 0;
}

AirTicket::~AirTicket() {
    //nothing to do
}

string AirTicket::getName() {
    return name;
}

void AirTicket::setName(string inName) {
    name = inName;
}

void AirTicket::setMiles(int inMiles) {
    miles = inMiles;
}

int AirTicket::calculatePrice() {
    int rPrice = 0;

    if (miles > 10000) rPrice = int(miles * 0.095);
    else rPrice = int(miles * 0.1);

    return rPrice;
}