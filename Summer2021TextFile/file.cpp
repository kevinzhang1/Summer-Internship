#include "file.h"

vector<string> File() {
	fstream file; //creates a fstream variable
    vector<string> vec;
	file.open("file.txt", ios::in); //opens file.txt
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
    vector<string> vec;
    string temp = "";

    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != del) temp += str[i];
        else {
            vec.push_back(temp);
            temp = "";
        }
    }
    vec.push_back(temp);
    return vec;
}