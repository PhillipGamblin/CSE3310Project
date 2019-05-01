#ifndef INTERFACE_H
#define INTERFACE_H
#include <ncurses.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

class Interface {
    public:
        std::vector<std::string> title;
        std::vector<std::string> login;
        std::vector<std::string> choices;
        std::vector<std::string> all_messages;

/*        std::vector<std::string> all_messages1 = {
            "<USER 1>: Trash!",
            "<USER 2>: Huh why did you invite me?",
            "<USER 2>: Smecklle smeagole smash.",
            "<USER 3>: Bullying Bully Bully",
            "<USER 2>: AHAHAHAHAH",
            "<USER 1>: BEEPBEEPBEEP",
            "<USER 3>: Uggghh",
            "<USER 2>: Ehhh?",
            };

        std::vector<std::string> all_messages2 = {
            "<USER 1>: Three!",
            "<USER 2>: Free free?",
            "<USER 2>: Tree tree tree.",
            "<USER 3>: Me me me",
            "<USER 2>: he he heee",
            "<USER 1>: She she she!!",
            "<USER 3>: Flee flee",
            "<USER 2>: Agree",
            };

        std::vector<std::string> all_messages3 = {
            "<USER 1>: Tired!",
            "<USER 2>: tired?",
            "<USER 2>: neeeed sleeep.",
            "<USER 3>: Zzzzzzz",
            "<USER 2>: Snore with smores",
            "<USER 1>: Shit",
            "<USER 3>: Stupid",
            "<USER 2>: Loser",
            };*/
        std::vector<std::string> options;

	int n_title;
        int n_choices; //sizeof(choices) / sizeof(choices[0]);
        int n_messages; //sizeof(all_messages) / sizeof(all_messages[0]);
        //const size_t n_messages1 = all_messages1.size();  //sizeof(all_messages1) / sizeof(all_messages1[0]);
        //const size_t n_messages2 = all_messages2.size(); //sizeof(all_messages2) / sizeof(all_messages2[0]);
        //const size_t n_messages3 = all_messages3.size();  //sizeof(all_messages3) / sizeof(all_messages3[0]);
        int n_options; //sizeof(options) / sizeof(options[0]);
        int n_login; //sizeof(login) / sizeof(login[0]);

	Interface();
        void print_highlight(WINDOW *inp_win, int highlight, int cur_y, int cur_x);
        void print_title(WINDOW*start, int index, char* part);
        int login_Page(WINDOW*start, WINDOW*input);
        void print_option_menu(WINDOW *new_win );
        void chatroom_Page( WINDOW*log, WINDOW*message, WINDOW*recc, WINDOW*rooms, WINDOW*chat_ops, WINDOW*curr);
};

#endif
