#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	string Inp = "-";
	while (Inp != "0") {
		cout << "Type what do you need!" << endl;
		cout << "1 - DArray7" << endl;
		cout << "2 - DArray17" << endl;
		cout << "3 - Longnumbers" << endl;
		cout << "-> ";
		cin >> Inp;
		if (Inp == "1") {
			DArray7();
		}
		else if (Inp == "2") {
			DArray17();
		}
		else if (Inp == "3") {
			Longnumbers();
		}
		else if (Inp != "0") {
			cout << "Error! Try again!" << endl;
		}
	}
}