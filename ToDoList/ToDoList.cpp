// Purpose: This file contains the main function for the ToDoList program.
#include <iostream>
#include <vector>
#include "including.h"
#include "ToDos.h"
#include "user.h"
#include "Validation.h"
using namespace std;

//namespace Validation {
//	bool isText(const string& text) {
//		for (char c : text) {
//			if (!isalpha(c) && c != ' ') {
//				return true;
//			}
//		}
//		return false;
//	}
//	bool idExist(const vector<ToDos>& collection, string& id) {
//		for (const ToDos& ToDo : collection) {
//			if (ToDo.getName() == id) {
//				return true;
//			}
//		}
//		return false;
//	}
//	bool isDigit(const string& text) {
//		for (char c : text) {
//			if (!isdigit(c)) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//
//}
//template <typename T=User> 
int findUserInCollection(string& username,vector <class User> &vec);
bool checkDate(string day, string month);
void Register(string &username, vector<class User> &users);

bool idExist(const vector<User>& collection, string& id);

int main() {
	vector<class User> users;
	cout << "Welcome to the ToDoList program!" << endl;
	while (true) {
		string username{}, decision{};
		bool exist{false};
		cout << "Please enter your username: ";
		cin.ignore();
		getline(cin, username);
		if (users.size() > 0 and idExist(users,username)) { //jeśli istnieje -> wczytywanie interfejsu użytkownika
				int k{ ::findUserInCollection(username,users) };
			while (true) {
				do { //USER INTERFACE
					cout << "Choose action: " << endl;
					cout << "1. Display ToDos" << endl;
					cout << "2. Add ToDo" << endl;
					cout << "3. Remove ToDo" << endl;
					cout << "4. Edit ToDo" << endl;
					cout << "5. Exit" << endl;
					cin >> decision;
					if (!regex_match(decision, regex("[1-5]+"))) {
						cout << "Invalid input!" << endl;
					}
				} while (!regex_match(decision, regex("[1-5]+")));
				if (decision == "1") {
					for (int i = 0; i <= users[k].getToDos().size() - 1; i++) {
						users[k].getToDos()[i].display();
						cout << "\n--------------------------------\n";
					}
				}
				else if (decision == "2") { // add new todos
					string name, description, priority;
					string day, month, year;
					vector<int>dueDate;
					bool validation1{}, validation2{};
					do {
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, name);
						validation1 = isText(name), validation2 = idExist(users[k].getToDos(), name);
					} while (validation1 or validation2);

					cout << "Enter description: ";
					getline(cin, description);

					cout << "Enter priority: ";
					getline(cin, priority);

					cout << "Enter due month: ";
					getline(cin, month);

					cout << "Enter due day: ";
					getline(cin, day);

				}
				else if (decision == "3") {
					string n{};
					do {

						for (int j = 0; j <= users.size() - 1; j++) {
							cout << ++j << ": " << endl;
							users[k].getToDos()[j].display(); cout << "\n--------------------------------\n";
						}
						cout << "Enter number of ToDos to delete: " << endl;//remove todo
						cin.ignore();
						getline(cin, n);
					} while (isDigit(n) and (stoi(n) > 0 && stoi(n) < users[k].getToDos().size() ? true : false));
					users[k].getToDos().erase(users[k].getToDos().begin() + stoi(n) - 1);
					cout << "DELETED!" << endl;
					system("cls");
				}
				else if (decision == "4") {
					cout << "Choose ToDos to edit: " << endl;//edit todos
					users[k].editToDo();
				}
				else if (decision == "5") {
					break; //exit
				}
			}			/*::users[::findUserInCollection(username)].displayTodos()*/;
			
		}
		else {// creating new account
			cout << "There are no users in the databas or user already exist" << endl;
			Register(username,users);
		}
		
		system("cls");
	};



	return 0;
}
int findUserInCollection(string& username,vector <User> &vec) {
	int i{ 0 };
	for (int m = 0; m < vec.size(); m++) {
		if (vec[m].getUsername() == username) {
			i = m;
		}
	}
	return i;
}
bool checkDate(string day, string month) {

	if (stoi(month) > 12 || stoi(month) < 1) {
		return false;
	}
	if (stoi(month) == 1 || stoi(month) == 3 || stoi(month) == 5 || stoi(month) == 7 || stoi(month) == 8 || stoi(month) == 10 || stoi(month) == 12) {
		if (stoi(day) > 31 || stoi(day) < 1) {
			return false;
		}
	}
	else if (stoi(month) == 2 && stoi(day)) {
		if (stoi(day) > 29 || stoi(day) < 1) {
			return false;
		}
	}
	else {
		if (stoi(day) > 30 || stoi(day) < 1) {
			return false;
		}

	}

	return true;
}
void Register(string &username, vector <class User> &users) {
	string decision{""};
	do {
		cout << "User does not exist. Do you want to create a new account? (Tak/Nie): " << endl;
		cin >> decision;
		if (regex_match(decision, regex("[Tt]ak"))) {
			string password{};
			cout << "Enter password: ";
			cin >> password;
			users.push_back(User(username, password));
			cout << "Account created!" << endl;
		}
		else if (regex_match(decision, regex("[Nn]ie"))) {
			break;
		}
		else {
			cout << "Invalid input!" << endl;
		}
		//adding to vector of users
		//jeśli nie istnieje -> jeśli zgoda -> tworzenie nowego użytkownika
		//jeśli nie istnieje -> jeśli nie zgoda -> powrót do wprowadzenia nazwy użytkownika

	} while (!regex_match(decision, regex("[Tt]ak")) || !regex_match(decision, regex("[Nn]ie")));
}
bool idExist(const vector<User>& collection, string& id) {
	for (const User& ToDo : collection) {
		if (ToDo.getUsername() == id) {
			return true;
		}
	}
	return false;
}