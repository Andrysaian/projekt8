#pragma once
#include <iostream>
#include <exception>
#include < string >
#include <string>

using namespace std;




class user// клас пользователя хранит пользователей имя пороль уровень доступа и количество предупреждений
{
public:
	user(string name, string pas, int levAcs, int levWorning);//конструктор
	user();
	~user();
	string getname();
	string getpas();
	int getlevAcs();
	int getlevWorning();
	void setname(string name);
	void setpas(string pas);
	void setlevAcs(int levAcs);
	void setlevWorning(int levWorning);
	void show();
private:
	string _name;//имя пользоватя 
	string _pas;//пароль 
	int _levAcs;//уровень доступа 
	int _levWorning;//количества предупреждений 

};
class hcat
{
public:
	hcat(string name1, string name2);
	~hcat();
	string getname1();
	string getname2();
	void addMesege(string mesege,string name);
	void showChat();
private:
	string _name1;
	string _name2;
	string** _box;
	int _leght;
};
class Boxhcat
{
public:
	Boxhcat(int leght);
	~Boxhcat();
	hcat* serhcChat(string name1, string name2);
	
private:
	hcat** _BoxH;
	int _leght;
};
class userBox1 {
public:
	userBox1(int leght);
	~userBox1();
	int getleght();
	user* getptr(int pos);
	bool addUser(user* newUser);
	void Show();
	void resais(int newLeght);
	user* serhuser(string str);
	bool chekUser(string name);


private:
	int _leght;
	user** _box;

};

bool paschek(string pas);
void creatUser(userBox1 &abox);
template <typename T> T** resaiz(T** aray, int &leght);
