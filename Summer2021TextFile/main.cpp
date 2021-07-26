// Summer2021TextFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "file.h"

int main() {
    vector<vector<string>> formateddata =formatdatafromfile("file.txt", ','); //reads data from file based on file name and puts it into a string vector of raw data
    for (vector<string> element : formateddata) { //prints out the formatted data to ensure that it was successful and correct
        for (string elements : element) cout << elements << endl;
    }
	return 0;
}

