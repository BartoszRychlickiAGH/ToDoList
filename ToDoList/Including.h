#ifndef INCLUDING_HPP
#define INCLUDING_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using std::endl,std::cin, std::cout,std::vector,std::string,std::regex,std::regex_match;

vector<int>setDate() {
	string day, month;
	bool validation1;
	do {
		cout << "Enter due month: ";
		getline(cin, month);
		if (regex_match(month,regex("[0-90-9]+"))) {
			validation1 = stoi(month) < 13 and stoi(month) > 0;
		}
		else {
			validation1 = false;
			cout << "Entered not a number input" << endl;
		}
		if (!validation1) { cout << "Entered wrong number of month" << endl; }
	} while (!validation1);
	do {
		cout << "Enter due day: ";
		getline(cin, day);
		if (regex_match(day, regex("[0-90-9]+"))) {
			if (stoi(month) == 1 or stoi(month) == 3 or stoi(month) == 5 or stoi(month) == 7 or stoi(month) == 8 or stoi(month) == 10 or stoi(month) == 12 and stoi(day) < 32 and stoi(month) > 0) { validation1 = true; }
			else if (stoi(month) == 2 and stoi(day) > 0 and stoi(day) < 30) { validation1 = true; }
			else if (stoi(month) == 4 or stoi(month) == 6 or stoi(month) == 9 or stoi(month) == 11 and stoi(day) < 31 and stoi(day) > 0) { validation1 = true; }
			else {
				validation1 = false;
				cout << "Entered wrong number of day in given month" << endl;
			}

		}
		else {
			validation1 = false;
			cout << "Entered not a number input" << endl;
		}
	} while (!validation1);
	vector<int>date{ stoi(day),stoi(month),2024 };
	return date;
}


#endif // INCLUDING_H
