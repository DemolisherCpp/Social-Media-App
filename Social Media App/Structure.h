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
	static int nooffriends;
public:
	user(std::string,std:: string);
	void addfriend(user*);
	~user();
};

int user::nooffriends = 0;


user::user(std::string idtext = "000",std:: string text="No Name") : existence(idtext) {
	name = text;
	friends = nullptr;
}

user::~user() {
	if (friends != nullptr) {
		delete[]friends;
	}
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