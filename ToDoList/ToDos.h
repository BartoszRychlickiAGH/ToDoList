#ifndef TODOS_H
#define TODOS_H
#include "including.h"


class ToDos {
	private:
		string name, description, priority; vector<int>dueDate;
	
	public:
		ToDos(string name, string description, string priority, vector<int>dueDate) {
			this->name = name;
			this->description = description;
			this->priority = priority;
			this->dueDate = dueDate;
		}

		string getName() const{
			return name;
		}
		string getDescription() const{
			return description;
		}
		string getPriority() const{
			return priority;
		}
		vector<int> getDueDate() const{
			return dueDate;
		}

		void setName(string name) {
			this->name = name;
		}
		void setDescription(string description) {
			this->description = description;
		}
		void setPriority(string priority) {
			this->priority = priority;
		}
		void setDueDate(vector<int>dueDate) {
			this->dueDate = dueDate;
		}

		virtual void display() {
			cout << "Name: " << name << endl;
			cout << "Description: " << description << endl;
			cout << "Priority: " << priority << endl;
			cout << "Due Date: " << dueDate[0] << "/" << dueDate[1] << "/" << dueDate[2] << endl;
		}

		virtual void Manage() {
			string n{};
			while (true) {
				do {
					system("cls");
					cout << "Choose an option: " << endl;
					cout << "1. Name" << endl;
					cout << "2. Description" << endl;
					cout << "3. Priority" << endl;
					cout << "4. Due Date" << endl;
					cout << "5. Exit" << endl;
					cin >> n;
				} while (!regex_match(n, regex("[1-5]+")));

				if (n == "1") {
					system("cls");
					cout << "Enter new name: ";
					cin.ignore();
					getline(cin, n);
					setName(n);
				}
				else if (n == "2") {
					system("cls");
					cout << "Enter new description: ";
					cin.ignore();
					getline(cin, n);
					setDescription(n);
				}
				else if (n == "3") {
					bool validation1;
					system("cls");
					do {
						cout << "Enter priority of todos(Urgent/Hard/Low): ";
						getline(cin, n);
						if (regex_match(n,regex("[A-Za-z]+"))) {
							if (regex_match(n, regex("[Uu]rgent")) or regex_match(n, regex("[Ll]ow")) or regex_match(n, regex("[Hh]ard"))) {
								validation1 = true;
							}
							else {
								validation1 = false;
							}
						}
						else {
							validation1 = false;
						}
					} while (!validation1);
					setPriority(n);
				}
				else if (n == "4") {
					system("cls");
					vector<int>date=setDate();
					setDueDate(date);
				}
				else {
					return;
				}
			};
		}//manage todos
};

#endif // TODOS_H