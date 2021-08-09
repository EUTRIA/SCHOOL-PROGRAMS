#pragma once
#include <fstream>
#include "Sequence.hpp"
#include "AirportRecord.h"

using namespace std;

typedef Sequence <AirportRecord> AirportSequence;

void doInputAirportDataFromFile(AirportSequence& airportData)
{
    //! replaces airportData
    //! ensures: #airportData = air16.txt
   
    string filename = "air16.txt";
    ifstream infile(filename);
    AirportRecord r;
    int dataSize;

    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
   
    if (infile.is_open()) {
        // The first item in the data file is an integer
        // it represents how many records are in the data file.
        infile >> dataSize;
        cout << "Number of Records :" << dataSize;
        for (int j = 0; j < dataSize; j++) {
            infile >> r.code;
            infile >> r.name;
            infile >> r.city;
            infile >> r.country;
            infile >> r.latitude_degree;
            infile >> r.latitude_minute;
            infile >> r.latitude_seconds;
            infile >> r.latitude_direction;
            infile >> r.longitude_degree;
            infile >> r.longitude_minutes;
            infile >> r.longitude_seconds;
            infile >> r.longitude_direction;
            infile >> r.altitude;

            
            airportData.addLast(r,airportData.length());
        } // end for
        infile.close();

    } // end if

} // doInputPersonDataFromFile>
