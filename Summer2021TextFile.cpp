// Summer2021TextFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream file;
	file.open("file.txt", ios::in);
	if (!file) {
		cout << "Open file failed";
	}
	else {
		cout << "Open file succeeded";
		file.close();
	}
	return 0;
}