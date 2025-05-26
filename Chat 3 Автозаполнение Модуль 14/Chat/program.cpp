#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "Mess.h"
#include "Chat.h"
#include "Graph.h"
#include "program.h"
#include "TrieNode.h"
using namespace std;

void program :: prog()
{
	Chat chat;
	chat.insert_lib();
	cout << "Hello! Welcome to our chat! " << endl;
	int f = 0;
	int count = 0;
	do
	{
		cout << "Press - 1 for register" << endl;
		if (count > 0)
		{
			cout << "Press - 2 to log in" << endl;
		}
		cout << "For exit press - 0" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "Exellent! Let's get acquainted)" << endl;
			string name;
			string login;
			string password;
			cout << "Enter name: "; cin >> name;
			cout << "Enter login: "; cin >> login;
			cout << "Enter password: "; cin >> password;
			chat.registerUser(login, password, name);
			count++;
			break;
		}

		case 2:
		{
			string login, password;
			cout << "Enter yor login: "; cin >> login;
			cout << "Enter password: "; cin >> password;
			if (chat.loginUser(login, password))
			{
				int option;
				do
				{
					cout << endl;
					cout << "Press: " << endl
						<< "1 - send message" << endl
						<< "2 - view message" << endl
						<< "3 - Add Friend" << endl
						<< "4 - Log out" << endl;
					cin >> option;

					switch (option)
					{
					case 1:
					{
						string message, recipient;
						cout << "Enter message: ";
						message = chat.T9();
						int n = 2;
						if (count > 1)
						{
							cout << "Whom to send message: " << endl;
							cout << "Private message - 1, ALL - 2 " << endl;
							cin >> n;
						}

						if (n == 2)
						{
							chat.SendMess(login, message);
						}
						else if (n == 1)
						{
							chat.listUsers(login);
							cout << "User's login, whom to send message: ";
							string recipient; cin >> recipient;
							chat.SendMess(login, message, recipient);
						}
						else
						{
							cout << "Error, try again" << endl;
						}
						cout << endl;
						break;
					}

					case 2:
					{
						cout << endl;
						chat.viewMess(login);
						cout << endl;
						break;
					}

					case 3:
					{
						chat.addFriend(login);
						break;
					}

					case 4:
					{
						cout << endl;
						chat.logoutUser(login);
						break;
					}

					default:
					{
						cout << "Invalid option! Please try again!" << endl;
					}
					}
				} while (option != 4);
			}
			break;
		}

		case 0:
		{
			f = 1;
			break;
		}

		default:
		{
			cout << "Invalid option! Please try again!" << endl;
		}
		}
	} while (f == 0);

	cout << "Goodbye!" << endl;
}