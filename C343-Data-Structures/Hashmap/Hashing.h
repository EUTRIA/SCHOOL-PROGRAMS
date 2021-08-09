#include "AirportRecord.h"
#include "Sequence.hpp"
using namespace std;

class HashEntry {
	private:
		string key;
	  AirportRecord value;
	public:

		HashEntry() {

		}
		HashEntry(string key, AirportRecord value) {
			this->key = key;
			this->value = value;
		}
		string getKey() {
			return key;
		}
		AirportRecord getValue() {
			return value;
		}	
};

const int TABLE_SIZE = 19;

class HashMap {
private :
	Sequence<HashEntry>**table;

public :
	HashMap();
	~HashMap();
	bool inMap(string key);
	void put(string key, AirportRecord value);
	int size();
	void remove(string key);
	int hash(string key);
	void swap(string key,AirportRecord& x);

	void outputMap();

};