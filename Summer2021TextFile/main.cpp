// Summer2021TextFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "file.h"

int main() {
    vector<vector<string>> vectors;
    vector<string> rawdata=File();
    char delimiter = ',';
    for (string element : rawdata) vectors.push_back(split(element, delimiter));

    for (vector<string> element : vectors) {
        for (string elements : element)
            cout << elements << endl;
    }
	return 0;
}

