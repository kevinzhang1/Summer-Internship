// Summer2021TextFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream file; //creates a fstream variable
	file.open("file.txt", ios::in); //opens file.txt
	if (!file) {
		cout << "Open file failed"; //if file variable doesn't exist, print this message
	}
	else {
		cout << "Open file succeeded"; //otherwise, print this message
		file.close(); //closes the file
	}
	return 0;
}
