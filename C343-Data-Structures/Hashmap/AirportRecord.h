#pragma once
#include<string>
#include<iostream>
using namespace std;


//
// Create AirportRecord
//
class AirportRecord {
public:
    string code;
    string name;
    string city;
    string country;

    int latitude_degree;
    int latitude_minute;
    int latitude_seconds;
    string latitude_direction;
    int longitude_degree;
    int longitude_minutes;
    int longitude_seconds;
    string longitude_direction;
    int altitude;


    AirportRecord() {}
    ~AirportRecord() {}

    void clear(void)
    {
        code = "";
        name = "";
        city = "";
        country = "";

        latitude_degree = 0;
        latitude_minute = 0;
        latitude_seconds = 0;
        latitude_direction = "";
        longitude_degree = 0;
        longitude_minutes = 0;
        longitude_seconds = 0;
        longitude_direction = "";
        altitude = 0;
    } // clear

    AirportRecord& operator = (AirportRecord& rhs)
    {
        //! replaces self
        //! restores rhs
        //! ensures: self = rhs

        code = rhs.code;
        name = rhs.name;
        city = rhs.city;
        country = rhs.country;

        latitude_degree = rhs.latitude_degree;
        latitude_minute = rhs.latitude_minute;
        latitude_seconds = rhs.latitude_seconds;
        latitude_direction = rhs.latitude_direction;
        longitude_degree = rhs.longitude_degree;
        longitude_minutes =rhs.longitude_minutes;
        longitude_seconds = rhs.longitude_seconds;
        longitude_direction = rhs.longitude_direction;
        altitude = rhs.altitude;

        return *this;
    } // operator =

    void transferFrom(AirportRecord& source)
    {
         //! replaces self
         //! clears source
         //! ensures: self = #source
         
        code = source.code;
        name = source.name;
        city = source.city;
        country = source.country;

        latitude_degree = source.latitude_degree;
        latitude_minute = source.latitude_minute;
        latitude_seconds = source.latitude_seconds;
        latitude_direction = source.latitude_direction;
        longitude_degree = source.longitude_degree;
        longitude_minutes = source.longitude_minutes;
        longitude_seconds = source.longitude_seconds;
        longitude_direction = source.longitude_direction;
        altitude = source.altitude;
      
    } // transferFrom

    // overloading the output operator.The outputSequence function will make use
    // of this. Must be friend becuse EmployeeRecord is not primitive type.

    friend ostream& operator << (ostream& os, AirportRecord& r)
    {
        os << "(" << r.code << "," << r.name << "," << r.city << "," << r.country <<","<< r.latitude_degree<< "," <<r.latitude_minute<<
            "," <<r.latitude_seconds<<","<<r.latitude_direction<<","<<r.longitude_degree<<","<<r.longitude_minutes<<","<<r.longitude_seconds<<","<<r.longitude_direction<<","<< r.altitude<< ")";
        return os;
    } // operator <<
};