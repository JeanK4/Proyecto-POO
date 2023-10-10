#include <iostream>
#include <string>


#ifndef USUARIO
#define USUARIO

using namespace std;

class usuario{
	private:
		string nickname;
		string password;
	public:
		usuario();
		void setNickname(string name);
		void setPassword(string pass);
		string getNickname();
		string getPassword();
};

#endif