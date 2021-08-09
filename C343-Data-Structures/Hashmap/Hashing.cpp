#include "FileReader.hpp"
#include "Hashing.hpp"

int main() {
	
	AirportSequence airportData;
	doInputAirportDataFromFile(airportData);
	//airportData.outputSequence();
	HashMap airportMap;

	 //putting all Airportrecords in map 
	for (int i = 0; i < airportData.length(); i++)
	{
		AirportRecord hashEntrySeq = airportData.entry(i);

		airportMap.put(hashEntrySeq.code,hashEntrySeq);
	}

	//Outputing Map
	airportMap.outputMap();

	//Amount of Records in Map
	cout<<"\nSize:"<<airportMap.size();

	cout << "\nIs YWG in map? " << boolalpha << airportMap.inMap("YWG");
	cout << "\nIs CMB in map? " << boolalpha << airportMap.inMap("CMB");
	
	//Removing HND
	cout << "\nRemoving HND";
	airportMap.remove("HND");

	//Amount of Records in Map
	cout << "\nSize:" << airportMap.size();

	//Outputting Map
	airportMap.outputMap();

	//Swapping record CFS with AirpordRecord:"SYD KINGSFORDSMITH SYDNEY AUSTRALIA 33 56 46 S 151 10 38 E 21"
	cout << "\nSwapping record CFS with AirpordRecord:\"SYD KINGSFORDSMITH SYDNEY AUSTRALIA 33 56 46 S 151 10 38 E 21\"\n";
	AirportRecord x; //intializing AirportRecord with values mentioned
	x.code = "SYD";
	x.name = "KINGSFORDSMITH";
	x.city = "SYDNEY";
	x.country = "AUSTRALIA";
	x.latitude_degree = 33;
	x.latitude_minute =56;
	x.latitude_seconds = 46;
	x.latitude_direction = "S";
	x.longitude_degree = 151;
	x.longitude_minutes = 10;
	x.longitude_seconds = 38;
	x.longitude_direction = "E";
	x.altitude = 21;
	
	airportMap.swap("CFS", x); //swapping
	
	//Outputting Map
	airportMap.outputMap();

	//Amount of Records in Map
	cout << "\nSize:" << airportMap.size();
	

}

