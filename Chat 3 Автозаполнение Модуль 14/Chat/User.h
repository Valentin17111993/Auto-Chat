#pragma once
#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

class User
{
	public:
		string _log;
		string _pass;
		string _name;

		User(); // Конструкторр по умолчанию: иниициализация пустых значений
		User(string log, string pass, string name); // Инициализация с заданными паролем логином и именем
		void SendMess(const string& mess, const string& recip = "") const // отправка сообщения и его вывод на экран
		{
			if (recip.empty())
			{
				cout << _name << " (to everyone): " << mess << endl;
			}
			else
			{
				cout << _name << " (to " << recip << "): " << mess << endl;
			}
		}
};
