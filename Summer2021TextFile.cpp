// Summer2021TextFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	fstream file; //creates a fstream variable
	file.open("file.txt", ios::in); //opens file.txt
	if (!file) cout << "Open file failed"; //if file variable doesn't exist, print this message
	else {
		cout << "Open file succeeded\n"; //otherwise, print this message
		string tp;
		while (getline(file, tp)) //read data from file and put it into string.
			cout << tp << "\n"; //prints the string
		file.close(); //closes the file
	}
	return 0;
}
