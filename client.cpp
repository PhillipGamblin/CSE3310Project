#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "client.hpp"


using namespace std;

int login(string username, string password)
{

      if( username_check(username)!=0) //checks if the username in username vector
	//if(find(Username_Vector.begin(), Username_Vector.end(), Userinput) != Username_Vector.end())
	{
			if(password_check(password) //checks if the password in the password vector
			{
				return 1;
			}
	}
	else if( Username_Vector.size() >= 50)
	{
		return 3;
	}
	else
	{
		return 2;
	}

}



//void Enter_IP_address( string IP);

//{
	//string IP;
//	cout<< "enter IP address";
//	cin>>IP;
//}

bool create_account(string username, string password)//  (should add password as another parameter)

{

	if( username_check(username)!=0)
	{
    Username_Vector.push_back(username);	//check if this is correct
	   if(password_check(password)!=0)      //checks if password is in the password-vector
     	{
	      Password_Vector.push_back(password); // password is being entered to the back of the vector
          return 1;
	    }
        else{
			return 0
		}
	}
    else
	{
      return 0;
	}


}

bool username_check(string Username)
{
	auto iter = find(Username_Vector.begin(), Username_Vector.end(),Username);

	if(iter != Username_Vector.end())
	    {
		   return 1;
	    }
	else
		{
		   return 0;
		}
}

bool password_check(string password)
{
	auto iter = find(Password_Vector.begin(), Password_Vector.end(),password);

	if(iter != Password_Vector.end())
	{
		return 1;
	}
	else
		{
		   return 0;
		}
}


bool delete_account( string username, stirng password) // should be void
{


	auto iter = find(Username_Vector.begin(), Username_Vector.end(),username);


			 if (iter != Username_Vector.end())
			 {
				 Username_Vector.erase(iter);
				 Password_Vector.erase(iter);
				 return 1;
			 }
			 else
			 {
				 return 0;
			 }
}
/*
void timer_logout()
{
	Timer timer;
	timer.start();
	int counter =0;
	while(timer.elapsedSeconds() < 180.00)
	{

	}
	timer.stop();
	exit(0);
	return 0;


}
*/
void mute()
{
	string username;
	char mssg[MAX_USER][MAX_PACKET];

	if (mssg == [mute])
	{
		if(username Username_Vector.size())
		{
			Username_Vector.erase();
		}
		else
		{
			cout << "ERROR"
		}

	else
	{
		return 0;
	}
}
