// Purpose: This file contains the main function for the ToDoList program.
#include <iostream>
#include <vector>
#include "including.h"
#include "ToDos.h"
#include "user.h"
#include "Validation.h"
//using namespace std;


int findUserInCollection(string& username,vector <class User> &vec);
bool checkDate(string day, string month);
void Register(string &username, vector<class User> &users);

bool idExist(const vector<User>& collection, string& id);

int main() {
	vector<class User> users;
	cout << "Welcome to the ToDoList program!" << endl;
	while (true) {
		string username{}, decision{}, password{};
		bool exist{false};
		cout << "Do you want to exit? (Yes/No): " << endl;
		cin >> decision;
		if (regex_match(decision, regex("[Yy]es"))) {
			system("cls");
			cout << "Exiting..." << endl;
			break;
		}
		cout << "Please enter your username: ";
		cin.ignore();
		getline(cin, username);
		cout << "\nEnter password: " << endl;
		getline(cin, password);
		if ((users.size() > 0) and idExist(users,username)) {
			if (password == users[::findUserInCollection(username,users)].getPassword()) {//jeśli istnieje -> wczytywanie interfejsu użytkownika
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
							cout << ++i << ": " << endl;
							users[k].displayTodos();
						}
					}
					else if (decision == "2") { // add new todos
						string name{}, description{}, priority{};
						string day{}, month{}, year{ "2024" };
						bool validation1{}, validation2{};
						do {
							cout << "Enter name of todos: ";
							cin.ignore();
							getline(cin, name);
							validation1 = isText(name), validation2 = idExist(users[k].getToDos(), name);
						} while (!validation1 and !validation2);

						cout << "Enter description of todos: ";
						getline(cin, description);

						cout << "Enter priority of todos: ";
						getline(cin, priority);
						do {
							cout << "Enter due month: ";
							getline(cin, month);
							if (isDigit(month)) {
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
							if (isDigit(day)) {
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
						ToDos toDo{ name,description,priority,{stoi(day),stoi(month),stoi(year)} };
						users[k].addToDo(toDo);

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
						} while (!isDigit(n) and stoi(n) > 0 and stoi(n) <= users[k].getToDos().size());
						users[k].getToDos().erase(users[k].getToDos().begin() + stoi(n) - 1);
						cout << "DELETED!" << endl;
						system("pause");
						system("cls");
					}
					else if (decision == "4") {
						cout << "Choose ToDos to edit: " << endl;//edit todos
						users[k].editToDo();
					}
					else if (decision == "5") {
						break; //exit
					}
				}
			}else{
				cout << " Wrong password! \nTry again! \n";
			}			/*::users[::findUserInCollection(username)].displayTodos()*/;
			
		}
		else {// creating new account
			cout << "There are no users in the database or user already exist" << endl;
			Register(username,users);
		}
		system("pause");
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
		cout << "Do you want to create a new account? (Yes/No): " << endl;
		cin >> decision;
		if (regex_match(decision, regex("[Yy]es"))) {
			string password{};
			cout << "Enter password: ";
			cin >> password;
			User client(username, password);
			users.push_back(client);
			cout << "Account created!" << endl;
		}
		else if (regex_match(decision, regex("[Nn]o"))) {
			break;
		}
		else {
			cout << "Invalid input!" << endl;
		}
		//adding to vector of users
		//jeśli nie istnieje -> jeśli zgoda -> tworzenie nowego użytkownika
		//jeśli nie istnieje -> jeśli nie zgoda -> powrót do wprowadzenia nazwy użytkownika

	} while (!regex_match(decision, regex("[Yy]es")) and !regex_match(decision, regex("[Nn]o")));
}
bool idExist(const vector<User>& collection, string& id) {
	for (const User& client : collection) {
		if (client.getUsername() == id) {
			return true;
		}
	}
	return false;
}