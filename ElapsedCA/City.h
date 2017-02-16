#pragma once
#include <utility>
#include <iostream>
#include <string>
using namespace std;

class City {
public:
	City();
	City(string nameIn, pair<double, double>GPSIn);
	string getName();
	//pair<double, double> getGPS();
	double getLatitude();
	double getLongitude();
	friend ostream& operator <<(ostream& outputStream, const City& cityObj);
	bool operator<(const City& c1) const;
	bool operator>=(const City& c1) const;
private:
	string name;
	pair<double, double> GPS;
};