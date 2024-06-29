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
		void removeToDo(string name) {
			for (int i = 0; i < toDos.size(); i++) {
				if (toDos[i].getName() == name) {
					toDos.erase(toDos.begin() + i);
				}
			}
		}
		void editToDo() {
			string n, input{};
			while (!regex_match(input, regex("[Tt]ak"))) {

				do {

					displayTodos();
					cout << "Enter the number of the ToDo you want to edit: ";
					cin >> n;
				} while (!isDigit(n));
				toDos[stoi(n) - 1].Manage();
				do {
					cout << "Do you want to edit another ToDo? (Tak/Nie): ";
					cin>> input;
				} while (!regex_match(input, regex("[Nn]ie")) || !regex_match(input, regex("[Tt]ak")));
				system("cls");
			}
		}
};

#endif // !USER_HPP

