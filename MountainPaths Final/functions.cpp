#include<vector>
#include <iostream>
#include "functions.h"
#include <limits>

using namespace std;

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
              int color_b, int start_row) {

    int dist = 0, currentRow = start_row, currentColumn = 0;

    do {
        //If statement for first row
        if (currentRow == 0) {
            //Declare and Initialize vector with the distances that would have to be traveled to any of the 3 possible tiles
            vector<int> possibleDistance(2);
            for (int i = 0; i < possibleDistance.size(); ++i) {
                possibleDistance.at(i) = abs(heightMap.at(currentRow).at(currentColumn) -
                                             heightMap.at(currentRow + i).at(currentColumn + 1));
            }

            //Accounts for the equality rules
            if (possibleDistance.at(0) == possibleDistance.at(1)) {
                possibleDistance.at(1) = numeric_limits<int>::max();
            }

            //Finds the spot which is the best to move to
            int minHeight = possibleDistance.at(0);
            int minIndex = 0;
            for (int i = 0; i < possibleDistance.size(); ++i) {
                if (possibleDistance.at(i) < minHeight) {
                    minHeight = possibleDistance.at(i);
                    minIndex = i;
                }
            }
            switch (minIndex) {
                //Position to the right
                case 0:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist = dist + possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    // currentRow stays the same
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
                    //Bottom right position
                case 1:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist = dist + possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    //CurrentRow is set to the row below
                    currentRow += 1;
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
            }
        }
        //if statement for last row
        else if (currentRow == heightMap.size() - 1) {
            vector<int> possibleDistance(2);
            for (int i = 0; i < possibleDistance.size(); ++i) {
                possibleDistance.at(i) = abs(heightMap.at(currentRow).at(currentColumn) -
                                             heightMap.at(currentRow + (i - 1)).at(currentColumn + 1));
            }

            //Accounts for the equality rules
            if (possibleDistance.at(1) == possibleDistance.at(0)) {
                possibleDistance.at(0) = numeric_limits<int>::max();
            }

            //Finds the spot which is the best to move to
            int minHeight = possibleDistance.at(0);
            int minIndex = 0;
            for (int i = 0; i < possibleDistance.size(); ++i) {
                if (possibleDistance.at(i) < minHeight) {
                    minHeight = possibleDistance.at(i);
                    minIndex = i;
                }
            }
            switch (minIndex) {
                //Top right position
                case 0:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist += possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    // currentRow moves to the row above
                    currentRow -= 1;
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
                    //Position to the right
                case 1:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist += possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    //CurrentRow stays the same
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
            }

        }
            //Everything else
        else {
            vector<int> possibleDistance(3);
            for (int i = 0; i < possibleDistance.size(); ++i) {
                possibleDistance.at(i) = abs(heightMap.at(currentRow).at(currentColumn) -
                                             heightMap.at(currentRow + (i - 1)).at(currentColumn + 1));
            }

            //Accounts for the equality rules
            if (possibleDistance.at(1) == possibleDistance.at(0) || possibleDistance.at(2) == possibleDistance.at(0)) {
                possibleDistance.at(0) = numeric_limits<int>::max();
            }
            if (possibleDistance.at(1) == possibleDistance.at(2)) {
                possibleDistance.at(2) = numeric_limits<int>::max();
            }

            //Finds the spot which is the best to move to
            int minHeight = possibleDistance.at(0);
            int minIndex = 0;
            for (int i = 0; i < possibleDistance.size(); ++i) {
                if (possibleDistance.at(i) < minHeight) {
                    minHeight = possibleDistance.at(i);
                    minIndex = i;
                }
            }
            switch (minIndex) {
                //Top right position
                case 0:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist += possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    // currentRow moves to the row above
                    currentRow -= 1;
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
                    //Position to the right
                case 1:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist += possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    //CurrentRow stays the same
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
                    //Bottom right position
                case 2:
                    //Paints current tile
                    r.at(currentRow).at(currentColumn) = color_r;
                    g.at(currentRow).at(currentColumn) = color_g;
                    b.at(currentRow).at(currentColumn) = color_b;
                    //Calculates distance to new position from current location and appends to dist
                    dist = dist + possibleDistance.at(minIndex);
                    //Changes currentRow and currentColumn to its new position
                    //CurrentRow is set to the row below
                    currentRow = currentRow + 1;
                    //currentCoulumn moves over to the next column
                    currentColumn += 1;
                    break;
            }
        }
    } while (currentColumn != heightMap[0].size() - 1);
    if (currentColumn == heightMap[0].size() - 1) {
        //Paints current tile
        r.at(currentRow).at(currentColumn) = color_r;
        g.at(currentRow).at(currentColumn) = color_g;
        b.at(currentRow).at(currentColumn) = color_b;
    }

    return dist;
}
