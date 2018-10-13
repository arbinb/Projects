#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"

class TemperatureDatabase {
public:
	TemperatureDatabase();
	~TemperatureDatabase();

	// The two functions below are required

	// Read the temperature records from the data file and populate the linked list
	// Implement for Part 1
	void loadData(const std::string& data_file);

	// Read the queries from the query file and perform a series of queries
	// Implement for Part 2
	void performQuery(const std::string& query_filename);
	static std::ostringstream os;
	//static std::ofstream results{"results.dat"};

private:
	// Linked list to store the temperature records. You need to properly populate
	// this link list.
	LinkedList records;
	// You can add any private member variables/functions you feel useful in this class.
};

#endif  // TEMP_DB
