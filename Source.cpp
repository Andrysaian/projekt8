#include "Header.h"
#include <iostream>
#include <exception>
#include <string>
using namespace std;
int main()
{
	userBox1 Box{ 5 };
	Boxhcat BoxChat{ 1 };
	user actUser("name", "123", 1, 1);
	cout << "Hello, welcome to the chat program " << endl;
	bool admin = true;
	while (admin)
	{
		cout << "please create an administrator" << endl;
		creatUser(Box);
		if (Box.getptr(0) !=nullptr)
		{
			admin = false;
		}
	}

	user* actuser = Box.getptr(0);
	bool MenuOn = true;
	while (MenuOn)
	{
		cout << "you are logged in as " << actuser->getname() << endl;
		cout << "select menu item " << endl;
		cout << "1) create user" << endl << "2) show list of users" << endl;
		cout << "3) send a message" << endl << "4) display chat with user " << endl;
		cout << "5) send a message to all users" << endl;
		cout << "6) change user" << endl << "7) close the program" << endl;
		int x;
		cin >> x;
		cin.ignore();
		switch (x)
		{
		  case 1:
		  {
			  creatUser(Box);
			  break;
		  }
		  case 2:
		  {
			  Box.Show();
			  break;
		  }
		  case 3:
		  {
			  string namePoluhatel;
			  cout << "enter the username to whom you want to send a message" << endl;
			  cin >> namePoluhatel;
			  cin.ignore();
			  bool nameTrue = false;
			  for (int i = 0; i < Box.getleght(); i++)
			  {
				  if (Box.getptr(i) != nullptr)
				  {
					  if (Box.getptr(i)->getname() == namePoluhatel)
					  {
						  nameTrue = true;
						  break;
					  }
					  else {}
				  }
			  }
			  if (nameTrue)
			  {
				  cout << "please enter message" << endl;
				  string mesege;
				  getline(cin, mesege, '\n');
				 // cin.ignore();
				  hcat* v = BoxChat.serhcChat(actuser->getname(), namePoluhatel);
				  v->addMesege(mesege, actuser->getname());
			  }
			  else
			  {
				  cout << "there is no such user" << endl;
			  }
			  break;
		  }
		  case 4:
		  {
			  cout << "Enter the name of the user you want to see your chat with" << endl;
			  string namex;
			  getline(cin, namex);
			 // cin.ignore();
			  if (Box.serhuser(namex) != nullptr)
			  {
				  BoxChat.serhcChat(actuser->getname(), namex)->showChat();
			  }
			  else { cout << "there is no such user" << endl; }
			  break;
		  }
		  case 5: 
		  {
			  cout << "please enter a message" << endl;
			  string mesege;
			  getline(cin, mesege);
			  string poluhatel;
			  for (int i = 0; i < Box.getleght(); i++)
			  {
				  if (Box.getptr(i) == nullptr)
				  {
					  continue;
				  }
				  poluhatel = Box.getptr(i)->getname();
				  BoxChat.serhcChat(actuser->getname(), poluhatel)->addMesege(mesege, actuser->getname());
			  }
		  
			  break;
			  
		  }
		  case 6:
		  {
			  actuser = nullptr;
			  string User1;
			  string Pas1;
			  while (actuser == nullptr)
			  {
				  cout << "enter username" << endl;
				  getline(cin, User1);				  
					  if (Box.chekUser(User1)) 
					  {
						  cout << "enter password"<< endl;
						  getline(cin, Pas1);
						  actuser = Box.serhuser(User1);
						  if (Pas1 == actuser->getpas())
						  {
							  break;
						  }
						  else
						  {
							  cout << "Incorrect password";
							  actuser = nullptr;
						  }
					  }
					  else { cout << "this is the user does not exist" << endl; }

			  }
			  break;
		  }
		  case 7:
		  {
			 MenuOn = false;
			 break;
		  }

		default:
			cin.clear();
			cin.ignore();
			string r;
			cin >> r;
			break;
		}
	}
	
		return 0;
}