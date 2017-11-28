// Lee Healy X00120179
/***************************************************************************************
*    The following code has been directly used from the following:
*
*	 Title: <Calculating the distance between 2 latitudes and longitudes>
*    Author: <MrTJ>
*    Date: <08/03/17>
*	 Type: <Source Code>
*    Availability: <http://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a>
*
***************************************************************************************/

#pragma once
#include "CalcDistance.h"

// This function converts decimal degrees to radians
double deg2rad(double deg) {
	return (deg * pi / 180);
}



//  This function converts radians to decimal degrees
double rad2deg(double rad) {
	return (rad * 180 / pi);
}



// Calculation function.
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}