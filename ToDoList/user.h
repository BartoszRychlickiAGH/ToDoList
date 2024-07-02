#ifndef USER_HPP
#define USER_HPP

#include "including.h"
#include "ToDos.h"
#include "Validation.h"


class User {
	private:
		string username, password;
		vector<ToDos> toDos;
	
	public:
		User(string username, string password) {
			this->username = username;
			this->password = password;
			this->toDos = {};
		}
		
		string getUsername() const {
			return username;
		}
		string getPassword() const {
			return password;
		}
		vector<ToDos> getToDos() const {
			return toDos;
		}
		
		void setUsername(string username) {
			this->username = username;
		}
		
		virtual void display() {
			cout << "Username: " << username << endl;
			cout << "Password: " << password << endl;

		}
		void displayTodos() {
			cout << "-----------------------------" << endl;
			for (ToDos toDo : toDos) {
				toDo.display(); 
				cout << endl<<"-----------------------------" << endl;
			}
		}
		void addToDo(ToDos toDo) {
			toDos.push_back(toDo);
		}
		void removeToDo(int i) {
			toDos.erase(toDos.begin() + i-1);
		}
		void editToDo() {
			string n, input{"Yes"};
			while (true) {
				do {
					displayTodos();
					cout << "Enter the number of the ToDo you want to edit: ";
					cin >> n;
				} while (!isDigit(n));
				toDos[stoi(n) - 1].Manage();
				do {
					cout << "Do you want to edit another ToDo? (Yes/No): ";
					cin.ignore();
					getline(cin, input);
				} while (!regex_match(input, regex("[Nn]o")) and !regex_match(input, regex("[Yy]es")));
				if (regex_match(input, regex("[Nn]o"))) { break; }
				system("cls");
			}
		}
};

#endif // !USER_HPP

