#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <fstream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <chrono>

std::vector<std::string> users;
std::vector<std::string> passwords;
std::vector<std::string> logged_in_users;

std::string filename = "sp.txt";

void load_file()
{
  std::string usernames;
  std::string passes;
  std::string message;
  std::string temp;
  std::fstream file;
  std::string line;

  file.open(filename); //change to proper name of load_file
  if(file.is_open())
  {
    std::getline(file,line);
    std::stringstream ss(line);

    while (std::getline(ss,temp,';'))
      users.push_back(temp);

    //passwords
    std::getline(file,line);
    std::stringstream sa(line);

    while (std::getline(sa,temp,';'))
      passwords.push_back(temp);
      /*
    getline(file,line);
    if(line[1] == "#")
    */


file.close();

  }
  else std::cerr << "Cannot load file";
  return;
}

void save_file(std::string line)
{
  std::vector<std::string> msg;
  std::string temp;
  std::stringstream ss(line);

  while (std::getline(ss,temp,'>'))
    msg.push_back(temp);

  std::fstream file;
  file.open(filename);
  char d = msg[0].at(0);
  if(d == '&')
  {
    file.seekg(-1,std::ios_base::end);

    bool kl = true;
    while(kl)
    {
      char c;
      file.get(c);
      if((int)file.tellg() <= 1)
      {
        file.seekg(0);
        kl = false;
      }
      else if(c = '\n')
      {
        kl = false;
      }
      else
      {
        file.seekg(-2,std::ios_base::cur);
      }
    }
    file << line <<std::endl;
    file.close();
  }
  else if(file.is_open() && d == '!')
  {
    for(int i = 0; i < users.size(); i++)
    {
      file << users[i] << ";";
    }
    file << std::endl;
    for(int i = 0; i < users.size(); i++)
    {
      file << passwords[i] << ";";
    }
    file <<std::endl;
      file.close();
    }
  else
    return;

}
int main()
{

  std::string s = "!>phillip>badpassword";


  save_file(s);
    load_file();
  for(int i = 0; i < users.size(); i++)
  {
    std::cout << users[i] << ";";
  }
  std::cout << std::endl;
  for(int i = 0; i < passwords.size(); i++)
  {
    std::cout << passwords[i] << ";";
  }
  std::cout << std::endl;


}
