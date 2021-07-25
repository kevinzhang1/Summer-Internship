// Summer2021TextFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "file.h"

int main() {
    vector<vector<string>> formateddata; //defines a vector for string vectors
    vector<string> rawdata=readfile(); //puts data read from text into a string vector of raw data
    char delimiter = ','; //defines deliminator as a comma
    for (string element : rawdata) formateddata.push_back(split(element, delimiter)); //loops through raw data, splits each string, and then pushes the results into the formated data

    for (vector<string> element : formateddata) { //prints out the formatted data to ensure that it was successful and correct
        for (string elements : element) cout << elements << endl;
    }
	return 0;
}

