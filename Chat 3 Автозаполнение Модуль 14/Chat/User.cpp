#include "User.h"
#include <iostream>
#include <string>
using namespace std;

User::User() : _log(""), _pass(""), _name("")
{
}

User::User(string log, string pass, string name) : _log(log), _pass(pass), _name(name)
{
}
