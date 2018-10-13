#include "TemperatureDatabase.h"
#include <fstream>
#include <sstream>
#include "ostream"
#include "string"
#include "math.h"
#include "iomanip"

using namespace std;

ostringstream TemperatureDatabase::os;
//ofstream TemperatureDatabase::results;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& data_file) {
	// Implement this function for part 1
    ifstream dataIn{data_file};
    if (!dataIn.is_open()) {
        cout << "Error: Unable to open input.dat" << endl;
        return;
    }
    string tmpString;
    while(getline(dataIn, tmpString)) {
        string location;
        int year;
        int month;
        double temp;
        string error = "ERROR";
        istringstream tmpStream(tmpString);
        if (!tmpStream.eof()) {
            tmpStream >> location;
            //cout << location << endl;
        } else {
            location = "ERROR";
            //cout << "End of stream" << endl;
        }
        if (!tmpStream.eof()) {
            tmpStream >> year;
            if (tmpStream.fail()) {
                year = -999;
            }
        } else {
            year = -999;
            //cout << "End of stream" << endl;
        }
        if (!tmpStream.eof()) {
            tmpStream >> month;
            if (tmpStream.fail()) {
                month = -999;
            }
        } else {
            month = -999;
            //cout << "End of stream" << endl;
        }
        if (!tmpStream.eof()) {
            tmpStream >> temp;
            if (tmpStream.fail()) {
                temp = -99.99;
            }
        } else {
            temp = -99.99;
            //cout << "End of stream" << endl;
        }
//        tmpStream >> location;
//        tmpStream >> year;
//        tmpStream >> month;
//        tmpStream >> temp;
        bool safeToInsert = true;
        if ((temp == -99.99) || (location.compare(error) == 0) || (year == -999) || (month == -999)) {
            cout << "Error: Other invalid input" << endl;
            safeToInsert = false;
        }
        else if ((temp < -50.0) || (temp > 50.0)) {
            cout << "Error: Invalid temperature " << temp << endl;
            safeToInsert = false;
        }
        if ((year < 1800) || (year > 2018)) {
            cout << "Error: Invalid year " << year << endl;
            safeToInsert = false;
        }
        if ((month < 1) || (month > 12)) {
            cout << "Error: Invalid month " << month << endl;
            safeToInsert = false;
        }
        if (safeToInsert){
            records.insert(location, year, month, temp);
            //cout << records << endl;
        }
    }
}

void TemperatureDatabase::performQuery(const string& query_filename) {
    // Implement this function for part 2
    //  Leave it blank for part 1
    ifstream queryIn{query_filename};
    if (!queryIn.is_open()) {
        cout << "Error: Unable to open query.dat" << endl;
        return;
    }
    //LinkedList toBeSorted = records;
    string tmpString;
    static ofstream results{"result.dat"};
    while (getline(queryIn, tmpString)) {
        string location;
        string type;
        int year_start;
        int year_end;
        istringstream tmpStream(tmpString);
        if (!tmpStream.eof()) {
            tmpStream >> location;
        } else {
            location = "ERROR";
        }
        if (!tmpStream.eof()) {
            tmpStream >> type;
        } else {
            type = "ERROR";
        }
        if (!tmpStream.eof()) {
            tmpStream >> year_start;
            if (tmpStream.fail()) {
                year_start = -999;
            }
        } else {
            year_start = -999;
        }
        if (!tmpStream.eof()) {
            tmpStream >> year_end;
            if (tmpStream.fail()) {
                year_end = -999;
            }
        } else {
            year_end = -999;
        }
        string avg = "AVG";
        bool checkAvg = false;
        string mode = "MODE";
        bool checkMode = false;
        bool safeToQuery = true;
        string error = "ERROR";
        if ((year_end == -999) || (year_start == -999) || (location.compare(error) == 0) || (type.compare(error)) == 0) {
            safeToQuery = false;
            cout << "Error: Other invalid query" << endl;
            goto here;
        }
            if (type.compare(avg) == 0) {
                checkAvg = true;
            } else if (type.compare(mode) == 0) {
                checkMode = true;
            } else {
                safeToQuery = false;
                cout << "Error: Unsupported query " << type << endl;
                goto here;
            }
            if ((year_start < 1800) || (year_end > 2018) || (year_start > year_end)) {
                cout << "Error: Invalid range " << year_start << "-" << year_end << endl;
                safeToQuery = false;
            }
            here:
            if (safeToQuery) {
//                LinkedList toBeSorted = records;
//            cout << endl << toBeSorted << endl;
                vector<double> temps = records.sortTemps(location, year_start, year_end);
                if (temps.empty()) {
                    results << location << " " << year_start << " " << year_end << " " << type << " unknown" << endl;
                }
                if (!temps.empty()) {
                    if (checkAvg) {
                        double average = 0.0;
                        double sum = 0.0;
                        double size = temps.size();
                        for (int i = 0; i < temps.size(); ++i) {
                            sum += temps.at(i);
                        }
                        if (size != 1.0) {
                            average = sum / size;
                            average = average - 0.000001;
                        } else
                            average = sum;
//                    cout << "Average is: " << average << endl;
                        results << location << " " << year_start << " " << year_end << " " << type << " " << average
                                << endl;
                    }
                    if (checkMode) {
                        int numMode = round(temps.at(0));
                        int current = round(temps.at(0));
                        int frequency = 0;
                        int max_frequency = 0;
                        for (int i = 0; i < temps.size(); ++i) {
                            if (round(temps.at(i)) == current) {
                                frequency += 1;
                                if (frequency >= max_frequency) {
                                    max_frequency = frequency;
                                    numMode = current;
                                }
                            } else {
                                current = round(temps.at(i));
                                frequency = 1;
                            }
                            if ((i == temps.size() - 1) && max_frequency == 1) {
                                numMode = round(temps.at(i));
                            }
                        }
                        results << location << " " << year_start << " " << year_end << " " << type << " " << numMode
                                << endl;
//                    cout << "Mode is: " << numMode << endl;
                    }
                }
            }
//        cout << endl;
        }
    }




