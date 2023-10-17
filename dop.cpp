#include "Header.h"
#include <iostream>
#include <exception>
#include < string >
using namespace std;

	

user::user(string name, string pas, int levAcs, int levWorning) //в??цчя?вч?я в?пццп ???я
{
	_name = name;
	_pas = pas;
	_levAcs = levAcs;
	_levWorning = levWorning;
};

user::user() = default;

user::~user() = default;

string user::getname() {
	return _name;
};
string user::getpas() {
	return _pas;
};
int user::getlevAcs() {
	return _levAcs;
};
int user::getlevWorning() {
	return _levWorning;
};
void user::setname(string name)
{
	_name = name;
};
void user::setpas(string pas)
{
	_pas = pas;
};
void user::setlevAcs(int levAcs) {
	_levAcs = levAcs;
}
void user::setlevWorning(int levWorning) {
	_levWorning = levWorning;
}
void user::show() {
	cout << getname() << getpas() <<endl;
}




userBox1::userBox1(int leght) {
	_leght = leght;
    _box = new user*[_leght];
	for (int i = 0; i < _leght; i++)
	{
		_box[i] = nullptr;	
	}
};
userBox1::~userBox1()
{
	for (int i = 0; i < _leght; i++)
	{
		if(_box[i] !=nullptr)
		{
			_box[i]->~user();
		}
		else
		{
			delete _box[i];
		}
	}
	delete _box;
}
bool userBox1::chekUser(string name)
{
	for (int i = 0; i < _leght; i++)
	{
		 if (_box[i] != nullptr)
		 {
			if (_box[i]->getname() == name)
			{
				return true;
			}
		 }
		
	}
	return false;
}
int userBox1::getleght() {
	return _leght;
}
user* userBox1::getptr(int pos) {
	if (pos >= 0 && pos < _leght)
		return  _box[pos];
	else
	{
		return nullptr;
	}
}
bool userBox1::addUser(user* newUser) {
	for (int i = 0; i < _leght; i++)
	{
		if (_box[i] == nullptr)
		{
			_box[i] = newUser;
			return true;
		}
	}
	return false;
}
void userBox1::Show() {
	for (int i = 0; i < _leght; i++)
	{
		if ( _box[i] != nullptr)
		{ cout << _box[i]->getname() << endl; }
	}


}
void userBox1::resais(int newLeght) {
	if (newLeght > _leght) 
	{
		user** nbox = new user * [newLeght];
		for (int i = 0; i < newLeght; i++)
		{
			nbox[i] = nullptr;
		}
		for (int i = 0; i < _leght; i++)
		{
			nbox[i] = _box[i];
		}
		_leght = newLeght;
		delete[] _box;
		_box = nbox;

	}
	
}
bool paschek(string pas) {
	cout << "please confirm your password" << endl;
	string pas2;
	cin >> pas2;
	if (pas == pas2)
		return true;
	else return false;
};
void creatUser(userBox1 &abox)
{
	string nname;
	string npas;
	
	bool chek = true;
	while (chek)
	{
		
		cout << "enter username" << endl;
		//cin.ignore();
		getline(cin, nname);
		
		for (int i = 0; i < abox.getleght(); i++)
		{
			if (abox.getptr(i) != nullptr)
			{
				if (nname == abox.getptr(i)->getname())
				{
					cout << "this user already exists " << endl;
					chek = true;
					break;
				}
				else
				{
					chek = false;
				}
			}
			else
			{
				chek = false;
			}
		};
	}
	
	cout << "enter password" << endl;
	cin >> npas;
	if (paschek(npas))
	{
		user* nuser = new user(nname, npas, 1, 1);

		if (abox.addUser(nuser))
		{
			cout << " you have successfully created a user " << nuser->getname() << endl;
			
		}
		else
		{
			abox.resais(int(abox.getleght() ));
			abox.addUser(nuser);
			
		}

	}
	else
	{
		cout << "the password does not match" << endl;
		cin.ignore();

	}
	
};
user* userBox1::serhuser(string str) {
	for (int i = 0; i < _leght; i++)
	{
		if (_box[i] != nullptr)
		{		
			if (_box[i]->getname() == str)
			{
				return _box[i];
			}
		};

	}
	return nullptr;
}
hcat::hcat(string name1, string name2)
{
	_name1 = name1;
	_name2 = name2;
	_leght = 1;
	_box = new string* [_leght];
	for (int i = 0; i < _leght; i++)
	{
		_box[i] = nullptr;
	}
}
hcat::~hcat()
{
	for (int i = 0; i < _leght; i++)
	{
		if (_box[i] != nullptr)
		{
			delete _box[i];
			continue;
		}
		else
		{
			delete _box[i];
		}
	}
	delete _box;
}
string hcat::getname1() 
{
	return _name1;
}
string hcat::getname2()
{
	return _name2;
}
void hcat::addMesege(string mesege, string name)
{
	bool creetString = false;
	for (int i = 0; i < _leght; i++)
	{
		if(_box[i] == nullptr)
		{

			 _box[i] =  new string(name + ") " + mesege);
			 creetString = true;
			break;
		}
		
	}
	if (creetString == false)
	{
	   _box =  resaiz(_box, _leght);
		addMesege(mesege, name);
	}
}
void hcat::showChat()
{
	cout << "чат пользоветельей" << _name1 <<" и " << _name2 << endl;
	for (int i = 0; i < _leght; i++)
	{
		if (_box[i] != nullptr )
		{
			cout << *_box[i] << endl;
		}
		
	}
	cout << "конец чата" << endl;
}
Boxhcat::Boxhcat(int leght)
{
	_leght = leght;
	_BoxH = new hcat * [_leght];
	for (int i = 0; i < _leght; i++)
	{
		_BoxH[i] = nullptr;
	}
};
Boxhcat::~Boxhcat()
{
	for (int i = 0; i < _leght; i++)
	{
		if (_BoxH[i] != nullptr)
		{
			_BoxH[i]->~hcat();
		}
		else
		{
			delete _BoxH[i];
		}
	}
	delete _BoxH;
}
hcat* Boxhcat::serhcChat(string name1, string name2)
{
	
	for (int i = 0; i < _leght; i++)
	{
		
		if (_BoxH[i] == nullptr)
		{
			continue;
		}
		string a = _BoxH[i]->getname1();
		string b = _BoxH[i]->getname2();
		if ((a == name1 && b == name2) ||
			(a == name2 && b == name1))
		{
			return _BoxH[i];
		}
			
		
	}
	
	for (int i = 0; i < _leght; i++)
	{
		if (_BoxH[i] == nullptr)
		{
			_BoxH[i] = new hcat(name1, name2);
			bool creetBoxH = true;
			return _BoxH[i];
		}
	}
	int x = _leght;
		_BoxH = resaiz(_BoxH, _leght);
		//serhcChat(name1, name2);
		_BoxH[x] = new hcat(name1, name2);
		return _BoxH[x];

};


template <typename T>
T** resaiz(T** aray, int &leght)
{
	int x = 10;
	   leght = leght + x;
		T** nbox = new T* [leght];
		for (int i = 0; i < leght; i++)
		{
			nbox[i] = nullptr;
		}
		for (int i = 0; i < leght-x; i++)
		{
			nbox[i] = aray[i];
		}
		
		delete[] aray;
		return nbox;
}
