#include "file.h"

vector<string> readfile(string filename) {
	fstream file; //creates a fstream variable
    vector<string> vec;
	file.open(filename, ios::in); //opens file.txt
	if (!file) cout << "Open file failed\n"; //if file variable doesn't exist, print this message
	else {
		cout << "Open file succeeded\n"; //otherwise, print this message
		string tp;
        while (getline(file, tp)) //read data from file and put it into string.
            vec.push_back(tp);
		file.close(); //closes the file
	}
    return vec;
}

vector<string> split(string str, char del) {
    vector<string> vec; //creates a string vector
    string temp = ""; //temporary string to hold string

    for (int i = 0; i < (int)str.size(); i++) { //loop through whole string
        if (str[i] != del) temp += str[i]; //if indexed part of string not deliminator, add it to temp string
        else {
            vec.push_back(temp); //otherwise, add it to string vector and reset temp string
            temp = "";
        }
    }
    vec.push_back(temp); //pushes last string into vector
    return vec; //returns string vector
}