#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

void create_userdata() {

	ofstream outfile("passwords.txt");
	hash<string> hasher;
	string password1 = "admin";
	string password2 = "car";
	string password3 = "house";
	string password4 = "dog";
	string password5 = "security";

	outfile << hasher(password1) << endl;
	outfile << hasher(password2) << endl;
	outfile << hasher(password3) << endl;
	outfile << hasher(password4) << endl;
	outfile << hasher(password5) << endl;

	outfile.close();
}

int main()
{
	string username;
	string password;
	ifstream infile;
	int hash_password = 0;
	int result = 0;
	hash<string> hasher;
	bool authenticated = false;
	string answer;

	create_userdata();
	
	while (!authenticated) {

		cout << "Give your username: ";
		cin >> username;

		cout << "Give your password: ";
		cin >> password;

		hash_password = hasher(password);

		try {
			infile.open("passwords.txt");
		}
		catch (const std::exception& error) {
			cout << error.what() << endl;
			return 0;
		}

		while (infile) {
			string line;
			getline(infile, line, '\n');

			try {
				result = atof(line.c_str());
				if (hash_password == result) {
					authenticated = true;
				}
			}
			catch (std::exception e) {
			}
		}
		infile.close();

		if (!authenticated) {
			cout << endl;
			cout << "Access denied. Try again!" << endl;
			cout << endl;
		}
	}
	cout << endl;
	cout << "You are now logged in. What do to now?" << endl;
	cin >> answer;
}