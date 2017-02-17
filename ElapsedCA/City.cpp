#pragma once
#include "City.h"

City::City() {

}

City::City(string nameIn, pair<double, double> GPSIn) {
	name = nameIn;
	GPS.first = GPSIn.first; // X Co-ordinate a.k.a Latitude
	GPS.second = GPSIn.second; // Y Co-ordinate a.k.a Longitude
}

ostream& operator <<(ostream& outputStream, const City& cityObj) {
	outputStream << cityObj.name << ": " << cityObj.GPS.first << "* N " << cityObj.GPS.second << "* W" << endl;
	return outputStream;
}


bool City::operator<(const City& c1) const {
	if (this->name.compare(c1.name) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool City::operator>=(const City& c1) const {
	if (this->name.compare(c1.name) > 0) {
		return true;
	}
	else {
		return false;
	}
}
