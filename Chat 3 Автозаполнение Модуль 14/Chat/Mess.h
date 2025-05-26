#pragma once
#include <string>
using namespace std;

class Mess
{
	public:
		string _sender; // логин отправителя
		string _recip; // логин получателя
		string _content; // содержание сообщения

		Mess(const string& sender, const string& content, const string& recip = "") : _sender(sender), _content(content), _recip(recip) {} // инициализация сообщения с заданым отправителем, содержанием и получателем
};
