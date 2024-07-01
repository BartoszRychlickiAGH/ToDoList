#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include "Including.h"
#include "ToDos.h"

bool isText(const string& text) {
	for (char c : text) {
		if (!isalpha(c) && c != ' ') {
			return false;
		}
	}
	return true;
}
bool idExist(const vector<ToDos>& collection, string& id) {
	for (const ToDos& ToDo : collection) {
		if (ToDo.getName() == id) {
			return true;
		}
	}
	return false;
}
bool isDigit(const string& text) {
	for (char c : text) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}


#endif // !VALIDATION_HPP
