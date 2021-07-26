#include "file.h"

vector<string> readfile(string filename);
vector<string> split(string str, char del);


/*this function formats data from file, takes file name as string and delimiter as character as inputs

input : filename    string 
        delim       char 
output:  vector<vector<string>>
*/
vector<vector<string>> formatdatafromfile(string filename, char delimiter) {
    vector<string> rawdata = readfile(filename);
    vector<vector<string>> formateddata; //defines a vector for formatted data
    for (string element : rawdata) formateddata.push_back(split(element, delimiter)); //loops through raw data, splits each string, and then pushes the results into the formated data
    return formateddata; //returns formatted data
}
/*this function reads data from file, takes file name as string as input

input : filename    string
output:  vector<string>
*/
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
/*this function splits a string based on a deliminator

input : str    string 
        del      char 
output:  vector<string>
*/
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