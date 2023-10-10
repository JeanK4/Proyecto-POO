#include "usuario.h"

usuario::usuario(){

}

void usuario::setNickname(string name){
	nickname = name;
}

void usuario::setPassword(string pass){
	password = pass;
}

string usuario::getNickname(){
	return nickname;
}

string usuario::getPassword(){
	return password;
}