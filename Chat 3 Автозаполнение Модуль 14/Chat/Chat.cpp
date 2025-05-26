#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "Mess.h"
#include "Chat.h"
using namespace std;

bool Chat::registerUser(const string& login, const string& password, const string& name)
{
	if (users.count(login))
	{
		cout << "login is already taken" << endl;
		return false;
	}
	users[login] = User(login, password, name);
	string log = login;
	friends->vname.push_back(log);
	int value = friends->vname.size() - 1;
	friends->addVertex(value);
	cout << "User " << name << " sucsessfuly registered" << endl;
	return true;
}

bool Chat::loginUser(const string& login, const string& password)
{
	if (!users.count(login) || users[login]._pass != password)
	{
		cout << "Error: incorrect login or password" << endl;
		return false;
	}
	onlineUsers.push_back(login); //помещаем пользователя в конец вектора пользователей, которые в сети.
	cout << "User " << login << " logged in" << endl;
	return true;
}

void Chat::logoutUser(const string& login)
{
	onlineUsers.erase(remove(onlineUsers.begin(), onlineUsers.end(), login), onlineUsers.end());
	cout << "User " << login << " logged out" << endl;
}


void Chat::listUsers(string login) const
{
	friends->findMinDistancesFloyd(login);
}

void Chat::viewMess(const string& login) const
{
	cout << "Chat messages for " << users.at(login)._name << ":" << endl;
	for (const auto& msg : publicMessage)
	{
		cout << msg._sender << " (to everyone): " << msg._content << endl;
	}
	if (privateMessage.count(login))
	{
		for (const auto& msg : privateMessage.at(login))
		{
			cout << msg._sender << " (to " << msg._recip << "): " << msg._content << endl;
		}
	}
}

void Chat::addFriend(const string& user_name)
{
	cout << endl << "Who is your friend ? Press 0 to cancel" << endl;
	listUsers(user_name);
	bool found = false;
	string friend_name;

	do
	{
		cout << "Enter friend name: ";
		cin >> friend_name;

		if (friend_name == "0")
		{
			break;
		}

		if (users.find(friend_name) == users.end())
		{
			cout << "Error: user " << friend_name << " not found." << endl;
			continue;
		}

		if (friend_name == user_name)
		{
			cout << "You can't add yourself as a friend." << endl;
			continue;
		}
		int index_st;
		int index_user;
		for (int i = 0; i < friends->vname.size(); i++)
		{
			if (friends->vname[i] == friend_name)
			{
				index_st = i;
			}
			if (friends->vname[i] == user_name)
			{
				index_user = i;
			}
		}
		if (friends->edgeExists(index_user, index_st))
		{
			cout << "You're already friends!" << endl;
			break;
		}

		friends->addEdge(user_name, friend_name);
		cout << "You have successfully added a friend: " << friend_name << endl;
		found = true;

	} while (!found);
}

string Chat::T9()
{
	string input;
	cout << "Enter a prefix to autocomplete: " << endl;
	string itog;
	while (true) 
	{
		cout << "> ";
		input = "";
		cin.ignore();
		getline(cin, input);
		vector<string> suggestions = trie->autocomplete(input);
		if (suggestions.empty()) {
			cout << "No suggestions found." << endl;
			cout << "Write your own message to send: ";
			input = "";
			getline(cin, input);
			itog = input;
			trie->insert(input);
			break;
		}
		else 
		{
			cout << "Suggestions: ";
			int i = 1;
			for (const string& suggestion : suggestions) 
			{
				cout << i << " - " << suggestion << " ";
			}
			cout << endl;
			cout << "Enter the supplement that suits you, write its number or write 0 and write your own message: ";
			int choice;
			cin >> choice;
			if (choice == 0) 
			{
				cout << "Enter the message you wanted to enter : ";
				string str;
				cin.ignore();
				getline(cin, str);
				trie->insert(str);
				itog = str;
				break;
			}
			else 
			{
				itog = suggestions[choice - 1];
				break;
			}
		}
	}
	return itog;
}

void Chat::insert_lib()
{
	trie->insert("Hello");
	trie->insert("How");
	trie->insert("are");
	trie->insert("you");
	trie->insert("Hi");
}