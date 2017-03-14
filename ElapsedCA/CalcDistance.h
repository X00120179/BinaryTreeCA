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

#ifndef DISTANCE_CALC
#define DISTANCE_CALC 

#include <cmath> 
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg);

// This function converts radians to decimal degrees
double rad2deg(double rad);


// Returns the distance between two points on the Earth.
// The distance between the two points in kilometers.
// lat1d Latitude of the first point in degrees.
// lon1d Longitude of the first point in degrees.
// lat2d Latitude of the second point in degrees.
// lon2d Longitude of the second point in degrees.
// Accessed 08/03/2017.
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

#endif