#ifdef CLIENT_H
#define CLIENT_H

#include<iostream>
#include<string>
#include<vector>

public:

 vector<string>Username_Vector;
 vector<string>Password_Vector;

int login(std::string username, std::string password, bool remember);
//void Enter_IP_address(std :: string IP);
bool create_account(std :: string username, std :: string password);
bool username_check(std::string username);
bool delete_account(std :: string username, std :: string password );
bool password_check(std :: string password);

//void delete_message(std:: string username);
//std :: string send_message();
//std :: string tab_completion();
void timer_logout();



#endif
