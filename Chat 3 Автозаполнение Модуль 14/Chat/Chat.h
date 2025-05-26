#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "Mess.h"
#include "TrieNode.h"
using namespace std;

class Chat
{
	public:
		unique_ptr<Graph> friends = make_unique<Graph>();
		unique_ptr<Trie> trie = make_unique<Trie>();

		bool registerUser(const string& login, const string& password, const string& name); // регистрирует нового пользователя. Возвращает true, если регистрация успешна, и false, если логин уже занят.
		bool loginUser(const string& login, const string& password); // выполняет вход пользователя в систему.
		void logoutUser(const string& login); // выход из системы.
		void SendMess(const string& senderLogin, const string& mess, const string& recip = "") // отправляет сообщение. Если получатель не указан, сообщение считается публичным, иначе — личным.
		{
			if (!recip.empty())
			{
				if (!users.count(recip))
				{
					cout << "Error: user " << recip << " not found " << endl;
					return;
				}
				privateMessage[senderLogin].emplace_back(senderLogin, mess, recip);
				privateMessage[recip].emplace_back(senderLogin, mess, recip);
				cout << users[senderLogin]._name << " (to: " << recip << ":) " << mess << endl;
			}
			else
			{
				publicMessage.emplace_back(senderLogin, mess);
				cout << users[senderLogin]._name << " (to everyone) " << mess << endl;
			}
		}
		void listUsers(string login) const; // выводит список всех зарегистрированных пользователей, исключая текущего пользователя.
		void viewMess(const string& login) const; // отображает все сообщения (публичные и личные) для данного пользователя.
		void addFriend(const string& user_name);
		string T9();
		void insert_lib();

	private:
		map<string, User> users; // Хранит зарегестрированных пользователей, ключ - логин.
		vector<string> onlineUsers; // Список пользователей в сети
		vector<Mess> publicMessage; // Публичные сообщения, отправленные всеми пользователями
		map<string, vector<Mess>> privateMessage; // Хранит личные сообщения пользователей, ключ - логин
};