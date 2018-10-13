#include "TemperatureDatabase.h"
#include <iostream>
#include <sstream>
#include "math.h"
#include "algorithm"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "iomanip"
#include "ios"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " data_file query_file" << endl;
        return 1;
    } else {
        //cout << "Howdy" << endl;
        TemperatureDatabase database;
        database.loadData(argv[1]);
        database.performQuery(argv[2]); // Will be done in Part 2
    }
//    string location;
//    string type;
//    int year_start;
//    int year_end;
//    string tmpString = "411038 AVG car 2015";
//    istringstream tmpStream(tmpString);
//    if (!tmpStream.eof()) {
//        tmpStream >> location;
//        cout << location << endl;
//    } else {
//        cout << "End of stream" << endl;
//    }
//    if (!tmpStream.eof()) {
//        tmpStream >> type;
//        cout << type << endl;
//    } else {
//        cout << "End of stream" << endl;
//    }
//    if (!tmpStream.eof()) {
//        tmpStream >> year_start;
//        cout << year_start << endl;
//        if (tmpStream.fail()) {
//            tmpStream.clear();
//            cout << "fail" << endl;
//            year_start = -999;
//            cout << year_start << endl;
//        }
//    } else {
//        cout << "End of stream" << endl;
//        year_start = -999;
//        cout << year_start << endl;
//    }
//    if (!tmpStream.eof()) {
//        tmpStream >> year_end;
//        cout << year_end << endl;
//    } else {
//        cout << "End of stream" << endl;
//        year_start = -999;
//        cout << year_start << endl;
//    }
//    if (!tmpStream.eof()) {
//        cout << "Happy" << endl;
//    } else {
//        cout << "End of stream" << endl;
//    }
}


