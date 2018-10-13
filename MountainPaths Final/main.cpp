#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include "functions.h"

using namespace std;

int main() {
    int mapHeight = 0, mapWidth = 0, tmpNum = 0, maxElev = 0, minElev = 0, numCount = 0;
    double shadeGrey = 0.0;
    string fileName;

    //Get inputs of hieght, width, and file name from user
    cout << "Enter the height of the image to be produced: ";
    cin >> mapHeight;
    cout << "Enter the width of the image to be produced: ";
    cin >> mapWidth;
    cout << "Enter the name of the file that contains the map data (ex. fileName.txt): " << endl;
    cin >> fileName;

    //Preform checks on user input
    if ((mapHeight <= 0 || mapWidth <= 0) || cin.fail()) {
        cout << "ERROR: Map dimensions invalid" << endl;
        return 1;
    }

    ifstream elevIn{ fileName };
    if (!elevIn.is_open()) {
        cout << "ERROR: Failed to open map data" << endl;
        return 1;
    }

    //Create 2d vector from data
    vector <vector <int>> elevData = vector <vector <int>>(mapHeight, vector<int>(mapWidth));
    for (int row = 0; row < mapHeight; ++row) {
        for (int col = 0; col < mapWidth; ++ col) {
            if (!elevIn.eof()) {
                elevIn >> tmpNum;
                elevData.at(row).at(col) = tmpNum;
                numCount = numCount +1;
            }
            if (elevIn.fail()) {
                numCount = 0;
            }

            //Find max and min elevation values
            if (row == 0 && col == 0) {
                maxElev = elevData.at(0).at(0);
                minElev = elevData.at(0).at(0);
            }
            if (elevData.at(row).at(col) > maxElev) {
                maxElev = elevData.at(row).at(col);
            }
            if (elevData.at(row).at(col) < minElev) {
                minElev = elevData.at(row).at(col);
            }
        }
    }
    //Check for size exceptions
    if ((numCount) != (mapHeight * mapWidth)) {
        cout << "ERROR: Amount of inputs does not match expected amount" << endl;
        return 1;
    }

    //Find and assign shades of grey
    vector <vector <double>> dred = vector <vector <double>>(mapHeight, vector<double>(mapWidth));
    vector <vector <double>> dgreen = vector <vector <double>>(mapHeight, vector<double>(mapWidth));
    vector <vector <double>> dblue = vector <vector <double>>(mapHeight, vector<double>(mapWidth));
    vector <vector <int>> red = vector <vector <int>>(mapHeight, vector<int>(mapWidth));
    vector <vector <int>> green = vector <vector <int>>(mapHeight, vector<int>(mapWidth));
    vector <vector <int>> blue = vector <vector <int>>(mapHeight, vector<int>(mapWidth));
    for (int row = 0; row < mapHeight; ++row) {
        for (int col = 0; col < mapWidth; ++col) {
            shadeGrey = static_cast<double >(elevData.at(row).at(col) - minElev) / (maxElev - minElev) * 255;
            dred.at(row).at(col) = round(shadeGrey);
            dgreen.at(row).at(col) = round(shadeGrey);
            dblue.at(row).at(col) = round(shadeGrey);
            red.at(row).at(col) = dred.at(row).at(col);
            green.at(row).at(col) = dgreen.at(row).at(col);
            blue.at(row).at(col) = dblue.at(row).at(col);
        }
    }
    int minDist = 0;
    int minRow = 0;
    for (int i = 0; i < elevData.size(); ++i) {
        int temp = colorPath(elevData, red, green, blue, 252, 25, 63, i);
        if (i == 1) {
            minDist = temp;
        }
        if (temp < minDist) {
            minDist = temp;
            minRow = i;
        }
    }
    cout << "Minimum distance: " << minDist << endl << "Located on row #: " << minRow << endl;
    minDist = colorPath(elevData, red, green, blue, 31, 253, 13, minRow);

    //Generate PPM File
    fileName.append(".ppm");
    ofstream ppmFile{ fileName };
    ppmFile << "P3" << endl << mapWidth << " " << mapHeight << endl << "255" << endl;
    for (int row = 0; row < mapHeight; ++row){
         for (int col = 0; col < mapWidth; ++col) {
            if (col == 0) {
                ppmFile << red.at(row).at(col);
            }
            else {
                ppmFile << " " << red.at(row).at(col);
            }
            ppmFile << " " << green.at(row).at(col);
            ppmFile << " " << blue.at(row).at(col);
        }
        ppmFile << endl;
    }
    return 0;
}