#ifndef STRUCTURE_H
#define STRUCTURE_H

#include<Phases.h>
#include <iostream>
#include<vector>

class user;

class comment {
	std::string text;
	std::string username;
public:
	comment(std::string, std::string);
	std::string gettext() {
		return text;
	}
	std::string getusername() {
		return username;
	}
	void settext(std::string a) {
		 text=a;
	}
	void setusername(std::string a) {
		 username=a;
	}
};

comment::comment(std::string a="No Name", std::string b="Nothing") {
	text = b;
	username = a;
}

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

class post : public existence {
	std::string description;
	int date;
	std::string picpath;
	std::vector <user*> likers;
	std::vector <comment*> comments;
	int noofcomments;
	int nooflikes;
public:
	post(std::string,std::string,int,std::string,int,int);
	std::string getdescription();
	int getdate();
	int getnoofcomments() {
		return noofcomments;
	}
	std::vector<user*> getlikers() {
		return likers;
	}
	std::string getpicpath() {
		return picpath;
	}
	std::vector <comment*> getcomments();
	comment* getcomment(int i) {
		return comments[i];
	}
	void addcomment(std::string,std::string);
	void setnooflikes(int);
	int getnooflikes();
	void addliker(user*);
	void removeliker(int);
	void setnoofcomments(int);
};

post::post(std::string exid = "000", std::string text = "Nothing", int dat=0,std ::string path="Blank.jpg",int g = 0,int s = 0) : existence(exid) {
	description = text;
	date = dat;
	picpath = path;
	noofcomments = g;
	nooflikes = 0;
}

std::string post::getdescription() {
	return description;
}

int post::getdate() {
	return date;
}

void post::setnooflikes(int a) {
	nooflikes = a;
}

void post :: setnoofcomments(int a) {
	noofcomments = a;
}

int post::getnooflikes() {
	return nooflikes;
}

std::vector <comment*> post ::getcomments() {
	return comments;
  }

void post::addliker(user* a) {
	likers.push_back(a);
}

void post::removeliker(int a) {
	std::vector<user*>::iterator it;

	it = likers.begin()+a;
	likers.erase(it);
	nooflikes = likers.size();
}

void post :: addcomment(std::string a, std::string b) {
	//comment dummy(a, b);
	comments.push_back(new comment(a,b));


}


class user :public existence {
	std::string name;
	std::vector<user*> friends;
	int nooffriends;
	static int noofusers;
	int noofposts;
	std::vector<post*> posts;
public:
	user(std::string,std:: string,int,int);
	void addfriend(user*);
	void setnoofusers(int);
	int getnoofusers();
	std::string getname();
	std::vector<user*> getfriends();
	std::string getfriendid(int);
	std::string getfriendname(int);
	void addpost(std::string, std::string, int, std::string,int);
	void setnooffriends(int);
	void setnoofposts(int);
	int getnooffriends();
	int getnoofposts();
	void setname(std::string);
	int getnoofpostcomments(int i) {
		return posts[i]->getnoofcomments();
	}
	std::string getpostid(int);
	std::string getposttext(int);
	int getpostdate(int);
	std::string getpostpicpath(int);
	std::vector<post*> getposts() {
		return posts;
	}
	post* getpost(int i) {
		return posts[i];
	}
};

int user::noofusers = 0;


user::user(std::string idtext = "000",std:: string text="No Name",int fr=0,int ps=0) : existence(idtext) {
	name = text;
	nooffriends = fr;
	noofposts = ps;
}

void user:: setnoofusers(int a) {
	noofusers = a;
}

void user :: setnoofposts(int a) {
	noofposts = a;
}

void user::setname(std::string a) {
	name = a;
}

int user::getnoofusers() {
	return noofusers;
}

std::string user::getname() {
	return name;
}

std::vector<user*> user::getfriends() {
	return friends;
}

std::string user::getfriendid(int a) {
	return (friends[a])->getid();
}
std::string user::getfriendname(int a) {
	return (friends[a])->getname();
}

void user::setnooffriends(int a) {
	nooffriends = a;
}

int user :: getnooffriends() {
	return nooffriends;
}

int user:: getnoofposts() {
	return noofposts;
}

std::string user::getpostid(int i) {
	return posts[i]->getid();
}
std::string user::getposttext(int i) {
	return posts[i]->getdescription();
}
int user::getpostdate(int i) {
	return posts[i]->getdate();
}
std::string user::getpostpicpath(int i) {
	return posts[i]->getpicpath();
}

void user::addfriend(user* add) {
	friends.push_back(add);
}

void user::addpost(std::string a = "000", std::string b = "Nothing", int c = 0, std::string d = "Blank.jpg",int p=0) {
	posts.push_back(new post(a, b, c, d,p));
}


#endif