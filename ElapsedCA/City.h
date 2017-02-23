#pragma once
#include <utility>
#include <iostream>
#include <string>
using namespace std;

class City {
public:
	City();
	City(string nameIn, double GPSFirstIn, double GPSSecondIn);
	friend ostream& operator <<(ostream& outputStream, const City& cityObj);
	bool operator==(const City& c1) const;
	bool operator<(const City& c1) const;
	bool operator>=(const City& c1) const;
private:
	string name;
	pair<double, double> GPS;
};