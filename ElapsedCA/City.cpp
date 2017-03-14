#pragma once
#include "City.h"
#include <queue>

City::City() {

}


City::City(string nameIn, double GPSFirstIn, double GPSSecondIn) {
	name = nameIn;
	GPS.first = GPSFirstIn; // X Co-ordinate a.k.a Latitude
	GPS.second = GPSSecondIn; // Y Co-ordinate a.k.a Longitude
}


ostream& operator <<(ostream& outputStream, const City& cityObj) {
	outputStream << cityObj.name << ": " << cityObj.GPS.first << "* N " << cityObj.GPS.second << "* W" << endl;
	return outputStream;
}


bool City::operator==(const City& c1) const {
	if (this->name == c1.name) {
		return true;
	} else {
		return false;
	}
}


bool City::operator<(const City& c1) const {
	if (this->name.compare(c1.name) < 0) {
		return true;
	}
	else {
		return false;
	}
}


bool City::operator>(const City& c1) const {
	if (this->name.compare(c1.name) > 0) {
		return true;
	}
	else {
		return false;
	}
}


double City::getLongitude() {
	return GPS.first;
}

double City::getLatitude() {
	return GPS.second;
}

string City::getName() {
	return name;
}


