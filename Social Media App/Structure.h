#ifndef STRUCTURE_H
#define STRUCTURE_H

#include<Phases.h>
#include <iostream>

class existence {
	std::string id;
public:
	existence(std::string);
	std::string getid();

};

existence::existence(std :: string text = "000") {
	id = text;
}

std::string existence:: getid() {
	return id;
}

class user :public existence {
	std::string name;
	user** friends;
	int nooffriends;
	static int noofusers;
public:
	user(std::string,std:: string,int);
	void addfriend(user*);
	void setnoofusers(int);
	int getnoofusers();
	std::string getname();
	user** getfriends();
	void setnooffriends(int);
	int getnooffriends();
	void setfriends(user**);
	~user();
	//friend void gui::loaddata(user**);
};

int user::noofusers = 0;


user::user(std::string idtext = "000",std:: string text="No Name",int fr=0) : existence(idtext) {
	name = text;
	friends = nullptr;
	nooffriends = fr;
}

user::~user() {
	if (friends != nullptr) {
		delete[]friends;
	}
}

void user:: setnoofusers(int a) {
	noofusers = a;
}

int user::getnoofusers() {
	return noofusers;
}

std::string user::getname() {
	return name;
}

user** user::getfriends() {
	return friends;
}

void user::setnooffriends(int a) {
	nooffriends = a;
}

int user :: getnooffriends() {
	return nooffriends;
}

void user :: setfriends(user**data) {
	friends = data;
}

void user::addfriend(user* add) {
	if (nooffriends==0) {
		friends = new user * [++nooffriends];
		friends[0] = add;
	}
	else {
		user** temp;
		temp = new user * [++nooffriends];
		for (int i = 0; i < nooffriends - 1; i++) {
			temp[i] = friends[i];
		}
		temp[nooffriends - 1] = add;
		delete[]friends;
		friends = temp;
	}
}

#endif